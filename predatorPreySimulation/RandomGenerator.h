/*!
 * \file RandomGenerator.h
 *
 * \author Jinchao Yang
 *
 * \brief Header for RandomGenerator class
 */

#ifndef RANDOM_GENERATOR_H_
#define RANDOM_GENERATOR_H_

#include <algorithm>
#include <random>
#include <vector>

/*!
 * \brief Random number generator class
 */
class RandomGenerator
{
    //! mt19937 random number generator instance
    std::mt19937 mt;

public:
    RandomGenerator(long seed);

    float getRandomGaussian(float average);
    float getRandomUniform(float max);

    long getRandomLong(long max);

    int getRandomInt(int max);

    /*!
     * \brief Gets a random from the element
     *
     * \param array an vector of elements
     *
     * \return a random element in the array
     * \return the default element value if the array is empty
     */
    template <class T> void shuffle(std::vector<T> &array)
    {
        std::shuffle(array.begin(), array.end(), mt);
    }

    /*!
     * \brief Gets a random from the element
     *
     * \param array an vector of elements
     *
     * \return a random element in the array
     * \return the default element value if the array is empty
     */
    template <class T> T getRandomElement(std::vector<T> &array)
    {
        // if the array is empty
        // return default value
        if (array.empty())
            return T();

        // return a random element in the array
        return array[getRandomLong(array.size())];
    }
};

#endif /* RANDOM_GENERATOR_H_ */
