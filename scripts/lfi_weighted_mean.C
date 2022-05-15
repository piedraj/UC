std::vector<float> v_value;
std::vector<float> v_error;


//------------------------------------------------------------------------------
//
// Compute the mean +- error in two different ways
//
//------------------------------------------------------------------------------
void lfi_weighted_mean()
{
  // Input values
  //----------------------------------------------------------------------------
  v_value.push_back(0.126);
  v_value.push_back(0.127);
  v_value.push_back(0.125);
  v_value.push_back(0.124);
  v_value.push_back(0.124);
  v_value.push_back(0.125);

  v_error.push_back(0.003);
  v_error.push_back(0.003);
  v_error.push_back(0.003);
  v_error.push_back(0.003);
  v_error.push_back(0.002);
  v_error.push_back(0.002);

  int n_measurements = v_value.size();


  // Weighted mean and error
  //----------------------------------------------------------------------------
  float mean_numerator   = 0.;
  float mean_denominator = 0.;

  for (int i=0; i<n_measurements; i++) {
    
    mean_numerator   += (v_value.at(i) / (v_error.at(i) * v_error.at(i)));
    mean_denominator += (           1. / (v_error.at(i) * v_error.at(i)));
  }

  float mean_value = mean_numerator / mean_denominator;
  float mean_error = 1. / sqrt(mean_denominator);

  printf("\n The weighted mean is %f +- %f\n", mean_value, mean_error);


  // Fit with a constant
  //----------------------------------------------------------------------------
  TH1F* h1 = new TH1F("h1", "h1", n_measurements, 0, n_measurements);

  for (int i=1; i<=6; i++) {

    h1->SetBinContent(i, v_value.at(i-1));
    h1->SetBinError  (i, v_error.at(i-1));
  }

  TCanvas* c1 = new TCanvas("c1", "c1");

  h1->Fit("pol0");

  printf("\n");
}
