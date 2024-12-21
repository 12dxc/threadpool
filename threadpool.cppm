module;

#include "threadpool.hpp"

export module threadpool;

export namespace dxc
{
    using dxc::MultiFuture;
    using dxc::PoolMode;
    using dxc::TASK_MAX_SIZE;
    using dxc::THREAD_MAX_IDLE_TIME;
    using dxc::THREAD_MAX_SIZE;
    using dxc::Threadpool;
} // namespace dxc