/*!
 * \file RandomGenerator.cpp
 *
 * \author Jinchao Yang
 *
 * \brief Implementation of RandomGenerator class
 *
 */

#include "RandomGenerator.h"

/*!
 * \brief RandomGenerator constructor with specified seed
 *
 * \param seed the seed for the mt19937
 *
 */
RandomGenerator::RandomGenerator(long seed) : mt(seed) {}

/*!
 * \brief Gets a random number generated in a Gaussian
 *        distribution with the specified average and the
 *        standard deviation of average / 3.
 *
 * Numbers less than 0 or greater than 2 * average are rejected
 *
 * \param average average value generated
 *
 * \return random number between 0 and 2 * average
 *
 */
float RandomGenerator::getRandomGaussian(float average)
{
    std::normal_distribution<float> dist(average, average / 3);

    float time = dist(mt);

    while (time <= 0 || time >= 2 * average)
    {
        time = dist(mt);
    }

    return time;
}

/*!
 * \brief Gets a random number uniformly generated between 0 and max
 *
 * \param max the max generatable value
 *
 * \return random number between 0 and max
 *
 */
float RandomGenerator::getRandomUniform(float max)
{
    std::uniform_real_distribution<float> dist(0, max);

    return dist(mt);
}

/*!
 * \brief Gets a random number uniformly generated between 0 and max
 *
 * \param max the max generatable value
 *
 * \return random number between 0 and max (exclusive)
 *
 */


int RandomGenerator::getRandomInt(int max)
{
    std::uniform_int_distribution<int> dist(0, max - 1);

    return dist(mt);
}
