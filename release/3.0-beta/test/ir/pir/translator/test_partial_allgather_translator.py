# Copyright (c) 2024 PaddlePaddle Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import unittest

import test_op_translator

import paddle
from paddle.base.layer_helper import LayerHelper

paddle.pir_utils._switch_to_old_ir_()


class TestPartialAllgetherOpTranslator(test_op_translator.TestOpTranslator):
    def append_op(self):
        self.op_type = "partial_allgather"
        x = paddle.ones(shape=(100, 2, 3), dtype='float32')
        out = paddle.ones(shape=(100, 2, 3), dtype='float32')
        attrs = {
            'nranks': 2,
            'rank': 0,
            'ring_id': 0,
            'use_calc_stream': False,
        }
        helper = LayerHelper(self.op_type)
        helper.append_op(
            type=self.op_type,
            inputs={"X": x},
            outputs={"Out": out},
            attrs=attrs,
        )

    def test_translator(self):
        self.check()


if __name__ == "__main__":
    unittest.main()
