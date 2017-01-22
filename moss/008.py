import argparse as ap

def parse_cla():
  """
  parses command line for arguments

  :return dict args: all parsed arguments
  """
  par = ap.ArgumentParser(description="Accepts user input")

  par.add_argument("infile",
                   help="file containing 1000-digit (or large) number",
		   type=str)

  args = par.parse_args()

  return args

def main():
  args = parse_cla()
  infile = args.infile

  print("Finding the 13 adjacent digits that produce greatest product...\n")

  # Read in entire file as single string
  # Remove all newline characters
  # Set 'thirteen' = first 13 digits
  # Scroll through string and update 'thirteen' if it has larger sum AND no zeros in it

  print("13 digits are: %s\n" % thirteen)
  print("Resulting product = %d\n" % product)

  return

if __name__ == "__main__":
  main()
