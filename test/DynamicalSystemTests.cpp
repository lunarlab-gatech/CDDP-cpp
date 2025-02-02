
#include <iostream>
#include <cassert> // For basic assertions
#include "cddp/cddp_core/DynamicalSystem.hpp"
#include "cddp/model/DoubleIntegrator.hpp"
#include "cddp/model/DubinsCar.hpp"

// Test case for the transition function of the DoubleIntegrator
bool testDoubleIntegratorTransition() {
    cddp::DoubleIntegrator system(4, 2, 0.1, 0);

    Eigen::VectorXd state(4);
    state << 1, 2, 0.5, -0.2; 

    Eigen::VectorXd control(2);
    control << 1.0, -0.5;

    Eigen::VectorXd expected_next_state(4);
    expected_next_state << 1.05, 1.98, 0.6, -0.25; 
    Eigen::VectorXd next_state = system.getDynamics(state, control);

    // Simple assertion: Could be more sophisticated
    if ((next_state - expected_next_state).norm() > 1e-6) {
        std::cout << "Expected: " << expected_next_state.transpose() << std::endl;
        std::cout << "Got: " << next_state.transpose() << std::endl;
        return false; // Test failed
    }
    return true; // Test passed
}

bool testDubinsCarTransition() {
    cddp::DubinsCar system(3, 2, 0.1, 0);

    Eigen::VectorXd state(3);
    state << 1, 2, 0.5; 

    Eigen::VectorXd control(2);
    control << 1.0, -0.5;

    Eigen::VectorXd expected_next_state(3);
    expected_next_state << 1.08775825618903728, 2.0479425538604203, 0.45; 
    Eigen::VectorXd next_state = system.getDynamics(state, control);

    // Simple assertion: Could be more sophisticated
    if ((next_state - expected_next_state).norm() > 1e-6) {
        std::cout << "Expected: " << expected_next_state.transpose() << std::endl;
        std::cout << "Got: " << next_state.transpose() << std::endl;
        return false; // Test failed
    }
    return true; // Test passed
}

int main() {

    if (testDoubleIntegratorTransition()) {
        std::cout << "DoubleIntegrator transition test passed!" << std::endl;
    } else {
        std::cout << "DoubleIntegrator transition test failed!" << std::endl;
    }

    if (testDubinsCarTransition()) {
        std::cout << "DubinsCar transition test passed!" << std::endl;
    } else {
        std::cout << "DubinsCar transition test failed!" << std::endl;
    }
    return 0;
}

