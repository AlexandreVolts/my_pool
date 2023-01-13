#ifndef WARP_SYSTEM_HPP_
#define WARP_SYSTEM_HPP_

namespace WarpSystem
{
    class QuantumReactor
    {
        public:
            QuantumReactor();
            bool isStable() const;
            void setStability(bool stability);
        private:
            bool _stability;
    };
    class Core
    {
        public:
            Core(QuantumReactor *coreReactor);
            QuantumReactor *checkReactor() const;
        private:
            QuantumReactor *_coreReactor;
    };
}

#endif