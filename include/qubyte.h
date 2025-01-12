#pragma once

#ifndef ENTNET-CPP_INCLUDE_QYBYTE_H
#define ENTNET-CPP_INCLUDE_QYBYTE_H


#include <memory>
#include <bitset>
#include <vector>
#include <random>
#include <cmath>
#include <thread>

namespace qutron {

    namespace entnet {

        /**
         * @brief Class implementation of Qutron's Qubyte.
         * 
         */
        class qubyte {

        private:

            int64_t _bits;
            int64_t _position;
            int64_t _momentum;
            int64_t _basis;
            int64_t _mask;
            std::mt19937 _rng;
            std::thread _evolve_thread;

            void update_position();

            int64_t momentum_mask(int64_t, int64_t);

        public:
            
            /**
             * @brief Construct a new qubyte object 
             * @param position 0
             * @param momentum 0
             * @param basis 0
             */
            qubyte();

            /**
             * @brief Construct a new qubyte object 
             * @param position 
             * @param momentum
             * @param basis
             */
            qubyte(int64_t, int64_t, int64_t);

            /**
             * @brief Destroy the qubyte object
             * 
             */
            ~qubyte();

            bool measure(int64_t);

            void evolve_loop();

            void stop();


        };





    };



};


#endif