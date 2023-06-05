/**
 * Open Space Program
 * Copyright © 2019-2022 Open Space Program Project
 *
 * MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once

#include "execute.h"
#include "tasks.h"
#include "top_tasks.h"

#include <vector>

namespace osp
{

void top_run_blocking(Tasks const& tasks, TaskGraph const& graph, TopTaskDataVec_t& rTaskData, ArrayView<entt::any> topData, ExecContext& rExec, WorkerContext worker = {});

void top_enqueue_quick(Tasks const& tasks, TaskGraph const& graph, ExecContext& rExec, ArrayView<TargetId const> enqueue);

inline void top_enqueue_quick(Tasks const& tasks, TaskGraph const& graph, ExecContext& rExec, std::initializer_list<TargetId const> enqueue)
{
    return top_enqueue_quick(tasks, graph, rExec, Corrade::Containers::arrayView(enqueue));
}

void write_dot_graph(std::ostream& rStream, Tasks const& tasks, TaskGraph const& graph, TopTaskDataVec_t& rTaskData);

} // namespace testapp
