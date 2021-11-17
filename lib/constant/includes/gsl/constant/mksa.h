/* const/gsl_const_mksa.h
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005,
 * 2006 Brian Gough
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
 * USA.
 */

#pragma once

namespace gsl::constant::mksa {

constexpr auto SPEED_OF_LIGHT = 2.99792458e8;              // m / s */
constexpr auto GRAVITATIONAL_CONSTANT = 6.673e-11;         // m^3 / kg s^2
constexpr auto PLANCKS_CONSTANT_H = 6.62606876e-34;        // kg m^2 / s
constexpr auto PLANCKS_CONSTANT_HBAR = 1.05457159642e-34;  // kg m^2 / s
constexpr auto ASTRONOMICAL_UNIT = 1.49597870691e11;       // m */
constexpr auto LIGHT_YEAR = 9.46053620707e15;              // m
constexpr auto PARSEC = 3.08567758135e16;                  // m
constexpr auto GRAV_ACCEL = 9.80665e0;                     // m / s^2
constexpr auto ELECTRON_VOLT = 1.602176462e-19;            // kg m^2 / s^2
constexpr auto MASS_ELECTRON = 9.10938188e-31;             // kg */
constexpr auto MASS_MUON = 1.88353109e-28;                 // kg
constexpr auto MASS_PROTON = 1.67262158e-27;               // kg
constexpr auto MASS_NEUTRON = 1.67492716e-27;              // kg
constexpr auto RYDBERG = 2.17987190389e-18;                // kg m^2 / s^2
constexpr auto BOLTZMANN = 1.3806503e-23;                  // kg m^2 / K s^2
constexpr auto BOHR_MAGNETON = 9.27400899e-24;             // A m^2 */
constexpr auto NUCLEAR_MAGNETON = 5.05078317e-27;          // A m^2
constexpr auto ELECTRON_MAGNETIC_MOMENT = 9.28476362e-24;  // A m^2
constexpr auto PROTON_MAGNETIC_MOMENT = 1.410606633e-26;   // A m^2
constexpr auto MOLAR_GAS = 8.314472e0;                     // kg m^2 / K mol s^2
constexpr auto STANDARD_GAS_VOLUME = 2.2710981e-2;         // m^3 / mol
constexpr auto MINUTE = 6e1;                               // s */
constexpr auto HOUR = 3.6e3;                               // s
constexpr auto DAY = 8.64e4;                               // s
constexpr auto WEEK = 6.048e5;                             // s
constexpr auto INCH = 2.54e-2;                             // m
constexpr auto FOOT = 3.048e-1;                            // m
constexpr auto YARD = 9.144e-1;                            // m
constexpr auto MILE = 1.609344e3;                          // m
constexpr auto NAUTICAL_MILE = 1.852e3;                    // m
constexpr auto FATHOM = 1.8288e0;                          // m
constexpr auto MIL = 2.54e-5;                              // m
constexpr auto POINT = 3.52777777778e-4;                   // m
constexpr auto TEXPOINT = 3.51459803515e-4;                // m
constexpr auto MICRON = 1e-6;                              // m
constexpr auto ANGSTROM = 1e-10;                           // m
constexpr auto HECTARE = 1e4;                              // m^2
constexpr auto ACRE = 4.04685642241e3;                     // m^2
constexpr auto BARN = 1e-28;                               // m^2
constexpr auto LITER = 1e-3;                               // m^3
constexpr auto US_GALLON = 3.78541178402e-3;               // m^3
constexpr auto QUART = 9.46352946004e-4;                   // m^3
constexpr auto PINT = 4.73176473002e-4;                    // m^3
constexpr auto CUP = 2.36588236501e-4;                     // m^3
constexpr auto FLUID_OUNCE = 2.95735295626e-5;             // m^3
constexpr auto TABLESPOON = 1.47867647813e-5;              // m^3
constexpr auto TEASPOON = 4.92892159375e-6;                // m^3
constexpr auto CANADIAN_GALLON = 4.54609e-3;               // m^3
constexpr auto UK_GALLON = 4.546092e-3;                    // m^3
constexpr auto MILES_PER_HOUR = 4.4704e-1;                 // m / s
constexpr auto KILOMETERS_PER_HOUR = 2.77777777778e-1;     // m / s
constexpr auto KNOT = 5.14444444444e-1;                    // m / s
constexpr auto POUND_MASS = 4.5359237e-1;                  // kg
constexpr auto OUNCE_MASS = 2.8349523125e-2;               // kg
constexpr auto TON = 9.0718474e2;                          // kg
constexpr auto METRIC_TON = 1e3;                           // kg
constexpr auto UK_TON = 1.0160469088e3;                    // kg
constexpr auto TROY_OUNCE = 3.1103475e-2;                  // kg
constexpr auto CARAT = 2e-4;                               // kg
constexpr auto UNIFIED_ATOMIC_MASS = 1.66053873e-27;       // kg
constexpr auto GRAM_FORCE = 9.80665e-3;                    // kg m / s^2
constexpr auto POUND_FORCE = 4.44822161526e0;              // kg m / s^2
constexpr auto KILOPOUND_FORCE = 4.44822161526e3;          // kg m / s^2
constexpr auto POUNDAL = 1.38255e-1;                       // kg m / s^2
constexpr auto CALORIE = 4.1868e0;                         // kg m^2 / s^2
constexpr auto BTU = 1.05505585262e3;                      // kg m^2 / s^2
constexpr auto THERM = 1.05506e8;                          // kg m^2 / s^2
constexpr auto HORSEPOWER = 7.457e2;                       // kg m^2 / s^3
constexpr auto BAR = 1e5;                                  // kg / m s^2
constexpr auto STD_ATMOSPHERE = 1.01325e5;                 // kg / m s^2
constexpr auto TORR = 1.33322368421e2;                     // kg / m s^2
constexpr auto METER_OF_MERCURY = 1.33322368421e5;         // kg / m s^2
constexpr auto INCH_OF_MERCURY = 3.38638815789e3;          // kg / m s^2
constexpr auto INCH_OF_WATER = 2.490889e2;                 // kg / m s^2
constexpr auto PSI = 6.89475729317e3;                      // kg / m s^2
constexpr auto POISE = 1e-1;                               // kg m^-1 s^-1
constexpr auto STOKES = 1e-4;                              // m^2 / s */
constexpr auto FARADAY = 9.6485341472e4;                   // A s / mol
constexpr auto ELECTRON_CHARGE = 1.602176462e-19;          // A s */
constexpr auto GAUSS = 1e-4;                               // kg / A s^2
constexpr auto STILB = 1e4;                                // cd / m^2 */
constexpr auto LUMEN = 1e0;                                // cd sr
constexpr auto LUX = 1e0;                                  // cd sr / m^2
constexpr auto PHOT = 1e4;                                 // cd sr / m^2
constexpr auto FOOTCANDLE = 1.076e1;                       // cd sr / m^2
constexpr auto LAMBERT = 1e4;                              // cd sr / m^2
constexpr auto FOOTLAMBERT = 1.07639104e1;                 // cd sr / m^2
constexpr auto CURIE = 3.7e10;                             // 1 / s */
constexpr auto ROENTGEN = 2.58e-4;                         // A s / kg
constexpr auto RAD = 1e-2;                                 // m^2 / s^2
constexpr auto SOLAR_MASS = 1.98892e30;                    // kg */
constexpr auto BOHR_RADIUS = 5.291772083e-11;              // m
constexpr auto NEWTON = 1e0;                               // kg m / s^2
constexpr auto DYNE = 1e-5;                                // kg m / s^2
constexpr auto JOULE = 1e0;                                // kg m^2 / s^2
constexpr auto ERG = 1e-7;                                 // kg m^2 / s^2
constexpr auto STEFAN_BOLTZMANN_CONSTANT = 5.67039934436e-8;  // kg / K^4 s^3
constexpr auto THOMSON_CROSS_SECTION = 6.65245853542e-29;     // m^2 */
constexpr auto VACUUM_PERMITTIVITY = 8.854187817e-12;   // A^2 s^4 / kg m^3
constexpr auto VACUUM_PERMEABILITY = 1.25663706144e-6;  // kg m / A^2 s^2
constexpr auto DEBYE = 3.33564095198e-30;               // A s^2 / m^2

}  // namespace gsl::constant::mksa