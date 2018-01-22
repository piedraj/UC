// Data members
//------------------------------------------------------------------------------
Float_t error_mass     =  0.001;  // kg
Float_t error_pressure =      2;  // Pa
Float_t gravity        =   9.81;  // m/s^2
Float_t surface        = 0.0013;  // m^2

Float_t coefficient[2];
Float_t error_coefficient[2];


// Function members
//------------------------------------------------------------------------------
void elevation_coefficient(TString conditions,
			   Int_t   index,
			   Float_t mass,
			   Float_t pressure);


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// main
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void examen()
{
  printf("\n");

  elevation_coefficient("max power", 0, 0.050, 60);
  elevation_coefficient("min power", 1, 0.044, 50);

  Float_t coefficient_difference       = fabs(coefficient[1] - coefficient[0]);
  Float_t error_coefficient_difference = sqrt(error_coefficient[0]*error_coefficient[0] + error_coefficient[1]*error_coefficient[1]);

  printf(" The difference is %.2f +- %.2f = %.1fsigma\n\n",
	 coefficient_difference, error_coefficient_difference, coefficient_difference/error_coefficient_difference);
}


void elevation_coefficient(TString conditions,
			   Int_t   index,
			   Float_t mass,
			   Float_t pressure)
{
  coefficient[index] = (gravity / surface) * (mass / pressure);

  error_coefficient[index] = coefficient[index] * sqrt((error_mass/mass)*(error_mass/mass) + (error_pressure/pressure)*(error_pressure/pressure));

  printf("   %s\n", conditions.Data());
  printf("   ---------\n");
  printf("    pressure = %2.0f +- %1.0f Pa\n", pressure, error_pressure);
  printf("        mass = %.3f +- %.3f kg\n", mass, error_mass);
  printf(" coefficient = %.2f +- %.2f\n", coefficient[index], error_coefficient[index]);
  printf("\n");
}
