/*
 * Copyright (c) 2017-2019 ARM Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef __ARM_COMPUTE_QUANTIZATION_ASYMM_HELPERS_H__
#define __ARM_COMPUTE_QUANTIZATION_ASYMM_HELPERS_H__

#include "arm_compute/core/Error.h"
#include "arm_compute/core/ITensor.h"
#include "arm_compute/core/Types.h"

namespace arm_compute
{
namespace quantization
{
/** Calculate quantized representation of multiplier.
 *
 * @param[in]  multiplier       Real multiplier.
 * @param[out] quant_multiplier Integer multiplier.
 * @param[out] shift            bit shift. A negative value indicates a left shift, while a positive value indicates a right shift
 *
 * @return a status
 */
Status calculate_quantized_multiplier(float multiplier, int *quant_multiplier, int *shift);
/** Calculate quantized representation of multiplier with value less than one.
 *
 * @param[in]  multiplier       Real multiplier.
 * @param[out] quant_multiplier Integer multiplier.
 * @param[out] right_shift      Right bit shift.
 *
 * @return a status
 */
Status calculate_quantized_multiplier_less_than_one(float multiplier, int *quant_multiplier, int *right_shift);
/** Calculate quantized representation of multiplier having value greater than one.
 *
 * @param[in]  multiplier           Real multiplier.
 * @param[out] quantized_multiplier Integer multiplier.
 * @param[out] left_shift           Left bit shift.
 *
 * @return a status
 */
Status calculate_quantized_multiplier_greater_than_one(float multiplier, int *quantized_multiplier, int *left_shift);

/** Calculate quantized representation of per-channel multipliers with value less than one.
 *
 * @param[in]      iq_info    Input quantization info.
 * @param[in]      wq_info    Weights quantization info.
 * @param[in]      oq_info    Output quantization info.
 * @param[in, out] stage_info GemmLowp output stage info
 *
 * @return a status
 */
Status calculate_quantized_multipliers_less_than_one(const QuantizationInfo &iq_info,
                                                     const QuantizationInfo &wq_info,
                                                     const QuantizationInfo &oq_info,
                                                     GEMMLowpOutputStageInfo &stage_info);

/** Get minimum and maximum values for the input quantized data type
 *
 * @return min and max values for the quantized data type
 */
std::pair<int, int> get_min_max_values_from_quantized_data_type(DataType data_type);
/** Compute quantized per-channel multipliers and shifts. As many multipliers
 * and shifts as output channels are computed. If weights are not quantized
 * per-channel, multipliers and shifts will end up being the same for each
 * channel.
 *
 * @param[in]  input                  Input tensor info.
 * @param[in]  weights                Weights tensor info.
 * @param[in]  output                 Output tensor info.
 * @param[in]  idx_ofms               Dimension index to get OFMs from the weights tensor.
 * @param[out] output_multipliers_ptr Pointer to the buffer where to store per-channel multipliers.
 * @param[out] output_shifts_ptr      Pointer to the buffer where to store per-channel shifts.
 *
 * @return min and max values for the quantized data type
 */
void compute_quantized_multipliers_and_shifts(const ITensorInfo *input,
                                              const ITensorInfo *weights,
                                              const ITensorInfo *output,
                                              unsigned int       idx_ofms,
                                              int32_t           *output_multipliers_ptr,
                                              int32_t           *output_shifts_ptr);
} // namespace quantization
} // namespace arm_compute
#endif /* __ARM_COMPUTE_IO_FILE_HANDLER_H__ */
