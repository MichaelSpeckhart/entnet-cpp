/**
 * @file qubyte_impl.cpp
 * @author Michael Speckhart 
 * @brief 
 * @version 0.1
 * @date 2025-01-12
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "../include/qubyte.h"

namespace qutron {

    namespace entnet {

        qubyte::qubyte() : _position(0), _momentum(0), _basis(0) {}

        qubyte::qubyte(int64_t position, int64_t momentum, int64_t basis) :
        _position(position), _momentum(momentum), _basis(basis) {

            this->_bits = 64;
            this->_mask = momentum_mask(this->_basis, this->_momentum);
            
            // Event loop runs in background by thread
            _evolve_thread = std::thread([this]() { this->evolve_loop(); });
        }

        qubyte::~qubyte() {
            this->stop();
        }




    };



};