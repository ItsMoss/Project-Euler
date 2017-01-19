import argparse as ap

def parse_cla():
  par = ap.ArgumentParser(description="Accepts user input")

  par.add_argument("--n",
                   help="integer number",
		   type=int,
		   default=None)

  args = par.parse_args()

  return args

def is_prime(n):
  if n < 2:
    return False
  for i in range(2, int(n//2+1)):
    if n % i == 0:
      return False

  return True

def find_lowest_prime_factor(n):
  for i in range(2, int(n//2+1)):
    if n % i == 0 and is_prime(i):
      return i

  return n

def main():
  args = parse_cla()
  if args.n is None:
    n = 600851475143
  else:
    n = args.n

  print("Finding the largest prime factor of %d...\n" % n)
  factmax = 0
  while n != 1:
    fact = int(find_lowest_prime_factor(n))
    if fact > factmax:
      factmax = fact
    n /= fact
  print("Largest prime factor = %d\n" % factmax)

  return

if __name__ == "__main__":
  main()
