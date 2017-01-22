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

def remove_char(a_string, char):
  """
  removes all instances of a character from a string

  :param str a_string: a string
  :param str char: a single character string
  :return str: input string with all newline characters removed
  """
  return a_string.replace(char, '')

def string_product(a_string):
  """
  multiplies all digits in a string consisting of only digit characters

  :param str a_string: string containing only digit characters
  :return int ans: the product
  """
  ans = 1
  for c in a_string:
    ans *= int(c)

  return ans

def find_max_13(a_string):
  """
  finds 13 adjacent characters in a string comprised of only digit charact\
  ers that yield a maximum product

  :param str a_string: a string consisting of only digit characters
  :return str ans: substring of input string with max product
  """
  ans = a_string[:13]
  for i in range(len(a_string) - 12):
    thirteen = a_string[i:i+13]
    if string_product(thirteen) > string_product(ans):
      ans = thirteen

  return ans

def main():
  args = parse_cla()
  infile = args.infile

  print("Finding the 13 adjacent digits that produce greatest product...\n")

  # Read in entire file as single string
  with open(infile, 'r') as f:
    number = f.read()

  # Remove all newline characters
  number = remove_char(number, '\n')

  # Scroll through string and update 'thirteen' if it has larger sum AND no zeros in it
  thirteen = find_max_13(number)
  product = string_product(thirteen)

  print("13 digits are: %s" % thirteen)
  print("Resulting product = %d\n" % product)

  return

if __name__ == "__main__":
  main()
