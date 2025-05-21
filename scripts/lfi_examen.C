// Data members
//------------------------------------------------------------------------------
Float_t pressure       =    60;  // Pa
Float_t error_pressure =   1.4;  // Pa
Float_t mass           = -0.062;  // kg
Float_t error_mass     = 0.001;  // kg
Float_t gravity        =  9.81;  // m/s^2
Float_t surface        = 0.016;  // m^2
Float_t density        =   1.2;  // kg/m^3

Float_t upper_pressure =  44 + 32 + 19 + 7;  // Pa
Float_t lower_pressure = -53 - 37 - 16 - 4;  // Pa


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// main
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void lfi_examen()
{
  Float_t velocity = sqrt(2. * pressure / density);

  Float_t error_velocity = (velocity / 2.) * (error_pressure / pressure);

  Float_t elevation_force = gravity * fabs(mass);

  Float_t coefficient = (gravity * fabs(mass)) / (pressure * surface);

  Float_t error_coefficient = coefficient * sqrt((error_mass/mass)*(error_mass/mass) + (error_pressure/pressure)*(error_pressure/pressure));

  Float_t estimated_force = 0.25 * (upper_pressure - lower_pressure) * surface * cos(M_PI * 30./180.);

  printf("\n                      ------- Part 1 -------\n");
  printf("             static-total pressure = %2.0f +- %2.1f Pa\n", pressure, error_pressure);
  printf("                              mass = %.3f +- %.3f kg\n", mass, error_mass);
  printf("                          velocity = %.3f +- %.3f m/s\n", velocity, error_velocity);
  printf("             elevation coefficient = %.3f +- %.3f\n", coefficient, error_coefficient);
  printf("\n                      ------- Part 2 -------\n");
  printf("   upper atmospheric-wing pressure = %3.1f/4 = %3.1f Pa\n", upper_pressure, 0.25 * upper_pressure);
  printf("   lower atmospheric-wing pressure = %3.1f/4 = %3.1f Pa\n", lower_pressure, 0.25 * lower_pressure);
  printf("          (upper-lower)/4 pressure = %3.1f Pa\n", 0.25 * (upper_pressure - lower_pressure));
  printf("      elevation force (using mass) = %.3f N\n", elevation_force);
  printf(" estimated force (using pressures) = %.3f N\n", estimated_force);
  printf("\n");
}
