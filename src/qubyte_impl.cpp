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
            // Stop all threads 
            this->stop();
        }

        void qubyte::stop() {
            if (_evolve_thread.joinable() == true) {
                _evolve_thread.join();
            } else {
                // Log here
            }
        }

        int64_t qubyte::momentum_mask(int64_t basis, int64_t momentum) {

        }

        int64_t qubyte::rotate(int64_t value, double theta) {
            if (theta == 0.0) return value;

            int64_t result = ((value << ((static_cast<int64_t>(_bits) - static_cast<int64_t>(std::round(theta))) % _bits)) ^ (value >> ((static_cast<int64_t>(_bits) + static_cast<int64_t>(std::round(theta))) % _bits)));
            return result;
        }

        void qubyte::evolve_loop() {
            this->_momentum = ((this->_mask % this->_position) != 0) * this->direction(this->_momentum) * (std::pow(2, this->_basis - 1)) + this->direction(this->_momentum);
            this->_position = this->rotate(this->_position, this->_momentum);
        }

        int64_t qubyte::direction(int64_t value) {
            if (value == 0) return 0;

            return std::abs(value) / value;
        }



    };



};