// Data members
//------------------------------------------------------------------------------
Float_t pressure       =    60;  // Pa
Float_t error_pressure =     2;  // Pa
Float_t mass           = 0.062;  // kg
Float_t error_mass     = 0.001;  // kg
Float_t gravity        =  9.81;  // m/s^2
Float_t surface        = 0.016;  // m^2
Float_t density        =   1.2;  // kg/m^3


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// main
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void examen_2019()
{
  Float_t force = gravity * mass;

  Float_t coefficient = (gravity * mass) / (pressure * surface);

  Float_t error_coefficient = coefficient * sqrt((error_mass/mass)*(error_mass/mass) + (error_pressure/pressure)*(error_pressure/pressure));

  Float_t upper_pressure = 0.25 * (44 + 32 + 19 + 7);

  Float_t lower_pressure = 0.25 * (-53 -37 -16 -4);

  Float_t estimated_force = (upper_pressure - lower_pressure) * surface * cos(M_PI * 30./180.);

  printf("\n");
  printf("             static-total pressure = %2.0f +- %1.0f Pa\n", pressure, error_pressure);
  printf("                              mass = %.3f +- %.3f kg\n", mass, error_mass);
  printf("             elevation coefficient = %.3f +- %.3f\n", coefficient, error_coefficient);
  printf("   upper atmospheric-wing pressure = %2.0f Pa\n", upper_pressure);
  printf("   lower atmospheric-wing pressure = %2.0f Pa\n", lower_pressure);
  printf("      elevation force (using mass) = %.3f N\n", force);
  printf(" estimated force (using pressures) = %.3f N\n", estimated_force);
  printf("\n");
}
