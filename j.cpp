#include <random>

typedef std::mt19937 rng_type;
std::uniform_int_distribution<rng_type::result_type> udist(0, 7);

rng_type rng;

int main()
{
  // seed rng first:
  rng_type::result_type const seedval = get_seed(); // get this from somewhere
  rng.seed(seedval);

  rng_type::result_type random_number = udist(rng);

  return random_number;
}