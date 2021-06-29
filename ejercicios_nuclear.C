// Data members
//------------------------------------------------------------------------------
Double_t N_Avogadro     = 6.0221367e23;    // [particles/mol]
Double_t C14_mass_u     = 14.003242;       // [u]
Double_t N14_mass_u     = 14.003074;       // [u]
Double_t K40_mass_u     = 39.9639982;      // [u]
Double_t Sr90_mass_u    = 89.90773;        // [u]
Double_t e_mass_u       = 5.48579903e-4;   // [u]
Double_t e_mass_MeV     = 0.51099906;      // [MeV]
Double_t proton_mass_kg = 1.672623e-27;    // [kg]
Double_t G              = 6.67430e-11;     // [N * m^2 / kg^2] 
Double_t k_e            = 8.987551787e9;   // [N * m^2 / C^2]
Double_t e              = 1.60217733e-19;  // [C]
Double_t eV             = 1.60217733e-19;  // [J]
Double_t r0             = 1.2e-15;         // [m]
Double_t Rb87_half_life = 4.88e10;         // [years]
Double_t K40_half_life  = 1.277e9;         // [years]
Double_t Sr90_half_life = 28.79;           // [years]
Double_t Au_A           = 197;
Double_t Au_Z           = 79;
Double_t alpha_Z        = 2;


//------------------------------------------------------------------------------
//
// Main
//
//------------------------------------------------------------------------------
void ejercicios_nuclear()
{
  //----------------------------------------------------------------------------
  //
  // Ejercicio 2a del examen de los temas 8 y 9 de FBIII (31 de mayo de 2021)
  //
  //    study guide for Tipler Physics, Fourth Edition
  //    Volumes 2 and 3, Chapters 22-41
  //    Mosca, Gautreau, Kyker
  //    Chapter 40 Nuclear Physics
  //    V. Questions and Answers
  //    Exercise 8. (page 244)
  //
  //----------------------------------------------------------------------------
  Double_t electron_maximum_energy = (C14_mass_u - N14_mass_u) * (e_mass_MeV / e_mass_u);  // [MeV]


  // Ejercicio 2b del examen de los temas 8 y 9 de FBIII (31 de mayo de 2021)
  Double_t alpha_energy_J = k_e * (alpha_Z * e) * (Au_Z * e) / (r0 * cbrt(Au_A));  // [J]

  Double_t alpha_energy_MeV = 1e-6 * alpha_energy_J / eV;  // [MeV]


  // Ejercicio 2c del examen de los temas 8 y 9 de FBIII (31 de mayo de 2021)
  Double_t N_Sr = 1e9;   // [atoms/gram]
  Double_t N_Rb = 2e10;  // [atoms/gram]

  Double_t N   = N_Rb;
  Double_t N_0 = N_Rb + N_Sr;

  Double_t rock_age_years = (Rb87_half_life / log(2.)) * log(2.1 / 2.);

  Double_t rock_age_seconds = rock_age_years * 365. * 24. * 3600.;


  //----------------------------------------------------------------------------
  //
  // Ejercicio 4a del examen de junio de FBIII (9 de junio de 2021)
  //
  //    https://phys.libretexts.org/Bookshelves/College_Physics/Book:_College_Physics_(OpenStax)
  //    31.E: Radioactivity and Nuclear Physics (Exercises)
  //    Exercise 76.
  //
  //----------------------------------------------------------------------------
  Double_t K40_decay_rate = 4140.;  // [Bq]

  Double_t K40_half_life_s = K40_half_life * 365. * 24. * 3600.;

  Double_t K40_lambda_s = log(2) / K40_half_life_s;
  
  Double_t N_K40 = K40_decay_rate / K40_lambda_s;  // decay_rate = R = lambda * N

  Double_t K40_mass_mg = 1e3 * N_K40 * K40_mass_u / N_Avogadro;

  Double_t K_mass_mg = 1e3 * 140.;


  // 4d - Examen de junio de FBIII (9 de junio de 2021)
  //----------------------------------------------------------------------------
  Double_t electrostatic_energy = k_e * e * e;                          // 1/r
  Double_t gravitational_energy = G * proton_mass_kg * proton_mass_kg;  // 1/r

  Double_t electrostatic_gravitational_ratio = electrostatic_energy / gravitational_energy;


  // 4a - Examen de julio de FBIII (6 de julio de 2021)
  //----------------------------------------------------------------------------
  Double_t Sr90_mass_g = 5e3;

  Double_t Sr90_R = 10.;  // desintegraciones / minuto

  Double_t Sr90_N0 = Sr90_mass_g * N_Avogadro / Sr90_mass_u;

  Double_t Sr90_half_life_min = Sr90_half_life * 365. * 24. * 60.;

  Double_t building_safe_time = (Sr90_half_life / log(2)) * log(log(2) * Sr90_N0 / (Sr90_half_life_min * Sr90_R));


  // Results
  //----------------------------------------------------------------------------
  printf("\n");
  printf(" [20210531 - 2a] electron maximum energy = %f u = %.3f MeV\n\n", C14_mass_u - N14_mass_u, electron_maximum_energy);
  printf(" [20210531 - 2b] alpha energy = %.3e J = %.3f MeV\n\n", alpha_energy_J, alpha_energy_MeV);
  printf(" [20210531 - 2c] rock age = %.3e s = %.3e years\n\n", rock_age_seconds, rock_age_years);
  printf("------------------------------------------------------------------\n\n");
  printf(" [20210609 - 4a] Potassium-40 half-life = %.3e years = %.3e s\n", K40_half_life, K40_half_life_s);
  printf("                                 lambda = %.3e 1/s\n", K40_lambda_s);
  printf("                                      N = %.3e atoms\n", N_K40);
  printf("                                   mass = %.3f g = %.0f mg\n", 1e-3 * K40_mass_mg, K40_mass_mg);
  printf("                               fraction = %.4f%s\n\n", 1e2 * K40_mass_mg / K_mass_mg, "%");
  printf(" [20210609 - 4d]   electrostatic energy = %.3e\n", electrostatic_energy);
  printf("                   gravitational energy = %.3e\n", gravitational_energy);
  printf("   gravitational / electrostatic energy = %.3e\n", 1. / electrostatic_gravitational_ratio);
  printf("   electrostatic / gravitational energy = %.3e\n\n", electrostatic_gravitational_ratio);
  printf("------------------------------------------------------------------\n\n");
  printf(" [20210706 - 4a] Strontium-90 half-life = %.3e min = %.3e s\n", Sr90_half_life_min, Sr90_half_life_min*60);
  printf("                                     N0 = %.3e atoms\n", Sr90_N0);
  printf("                     Building safe time = %.2f years = %.3e s\n\n", building_safe_time, building_safe_time*365*24*3600);
}
