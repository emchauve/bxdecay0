/** test_std_random.cxx
 *
 * Copyright 2017 François Mauger <mauger@lpccaen.in2p3.fr>
 * Copyright 2017 Normandie Université
 *
 * This file is part of BxDecay0.
 *
 * BxDecay0 is free software: you  can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free  Software Foundation, either  version 3 of the  License, or
 * (at your option) any later version.
 *
 * BxDecay0 is distributed  in the hope that it will  be useful, but
 * WITHOUT  ANY   WARRANTY;  without  even  the   implied  warranty  of
 * MERCHANTABILITY or  FITNESS FOR A  PARTICULAR PURPOSE.  See  the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BxDecay0.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

// Standard library:
#include <cstdlib>
#include <exception>
#include <iostream>
#include <random>

// This project:
#include <bxdecay0/std_random.h>

/* Test
 * \code
 * $ bxdecay0-test_std_random | gsl-histogram 0 1 50 > a.hist
 * $ gnuplot
 * gnuplot> plot [0:1][0:30] 'a.hist' u (0.5*(($1)+($2))):($3) notitle with histeps
 * \endcode
 *
 */
int main()
{
  int error_code = EXIT_SUCCESS;
  try {

    std::default_random_engine generator;
    bxdecay0::std_random prng(generator);
    for (int i = 0; i < 1000; i++) {
      std::cout << prng() << "\n";
    }

  } catch (std::exception & error) {
    std::cerr << "[error] " << error.what() << std::endl;
    error_code = EXIT_FAILURE;
  } catch (...) {
    std::cerr << "[error] "
              << "Unexpected exception!" << std::endl;
    error_code = EXIT_FAILURE;
  }
  return error_code;
}
