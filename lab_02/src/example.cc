#include <iostream>

#include "errors.hpp"
#include "vector.hpp"

void example()
{
    try
    {
        std::cout << "---VECTOR TESTING STARTED---" << std::endl << std::endl;

        std::cout << "---TESTING CONSTRUCTORS---" << std::endl << std::endl;

        Vector<double> vector_1;

        std::cout << "Default constructor: " << vector_1 << std::endl;

        Vector<double> vector_2;
        Vector<double> vector_3(3, 3.0, 4.0, 0.0);

        std::cout << "vector_2() is empty" << vector_2.IsEmpty() << std::endl;

        std::cout << "Constructors with parameters: " << vector_2 << "; ";
        std::cout << vector_3 << std::endl;

        double array_1[5] = {5, 1, 7, 4, 0};
        Vector<double> vector_4(5, array_1);

        std::cout << "From array to vector: " << vector_4 << std::endl;

        Vector<double> vector_5(vector_3);

        std::cout << "From one vector to another: " << vector_5 << std::endl;

        std::cout << std::endl << "---TESTING METHODS---" << std::endl << std::endl;

        std::cout << "Length of the vector (3, 4, 0) - " << vector_3.GetLength() << std::endl;

        std::cout << "Size of the vector (3, 4, 0) - " << vector_3.GetSize() << std::endl;

        std::cout << "Get 2nd element from the vector {5, 1, 7, 4, 0} - "<< vector_4.GetElement(1) << std::endl;

        std::cout << "Multiply the vector by 10 - " << (vector_4 *= 10) << std::endl;

        std::cout << "Divide the vector by 10 - " << (vector_4 /= 10) << std::endl;

        std::cout << "Subtract {3, 4, 0} from {5, 1, 7, 4, 0} - " << (vector_4 -= vector_3) << std::endl;

        std::cout << "Change to the opposite direction {3, 4, 0} - " << (-vector_3) << std::endl;

        Vector<double> vector_6 {1., 2., 3., 4., 5.};

        std::cout << "Initializing vector {1., 2., 3., 4., 5.} - " << vector_6 << std::endl;

        vector_6[2] = 10.;

        std::cout << "Changing the 3rd element with operator [] - " << vector_6 << std::endl;

        vector_6.SetElement(3, 11.);

        std::cout << "Changing the 4th element using 'SetElement' method - " << vector_6 << std::endl;

        vector_6 = vector_6.GetUnitVector();

        std::cout << "Getting the unit vector from {1, 2, 10, 11, 5} - " << vector_6 << std::endl;

        Vector<double> vector_7(3, 3.0, 4.0, 0.0);

        std::cout << "Vector multiplication of {3, 4, 0} and {3, 4, 0} - " << (vector_3 &= vector_7) << std::endl;

        Vector<int> vector_8(2, 10, 0);
        Vector<int> vector_9(2, 0, 10);

        std::cout << "The angle between vectors {10, 0} and {0, 10} - " << vector_8.GetAngle(vector_9) << std::endl;

        Vector<double> vector_10(2, 5., 5.);
        Vector<double> vector_11(2, 10., 0.0);

        std::cout << "The angle between vectors {5, 5} and {10, 0}: " << vector_10.GetAngle(vector_11) << std::endl;

        Vector<double> vector_12(2, 20., 20.0);

        std::cout << "Checking collinearity of vectors {5, 5} and {20, 20} - ";
        std::cout << vector_10.AreCollinear(vector_12) << std::endl;

        std::cout << "Scalar multiplication of {5, 5} and {10, 0} - " << vector_10 * vector_11 << std::endl;

        Vector<int> vector_13(4, 1, 0, 0, 0);

        std::cout << "Is vector {4, 1, 0, 0, 0} of length 1? - " << vector_13.IsUnit() << std::endl;

        std::cout << "Are vectors {0, 0, 0} and {3, 4, 0} equal? - " << (vector_3 == vector_7) << std::endl;

        std::cout << "Are vectors {0, 0, 0} and {3, 4, 0} not equal? - ";
        std::cout << (vector_3 != vector_7) << std::endl << std::endl;

        std::cout << "---VECTOR TESTING FINISHED---" << std::endl;
    }
    catch (BaseError& error)
    {
        std::cout << error.what() << std::endl;
    }
}
