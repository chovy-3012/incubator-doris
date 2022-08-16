// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#include "vec/aggregate_functions/aggregate_function_sort.h"

#include "vec/aggregate_functions/aggregate_function_combinator.h"
#include "vec/aggregate_functions/aggregate_function_simple_factory.h"
#include "vec/common/typeid_cast.h"
#include "vec/data_types/data_type_nullable.h"

namespace doris::vectorized {

AggregateFunctionPtr transform_to_sort_agg_function(const AggregateFunctionPtr& nested_function,
                                                    const DataTypes& arguments,
                                                    const SortDescription& sort_desc) {
    DCHECK(nested_function != nullptr);
    if (nested_function == nullptr) {
        return nullptr;
    }

    return std::make_shared<AggregateFunctionSort<AggregateFunctionSortData>>(nested_function,
                                                                              arguments, sort_desc);
};

} // namespace doris::vectorized
