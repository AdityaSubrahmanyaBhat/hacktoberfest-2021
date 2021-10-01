# Finds how many zeroes are in the factorial of n
# USER INPUT: number n
# OUTPUT: There are x zeroes in n! or n(input)!

# Example:
# INPUT: 20
# OUTPUT: There are 7 zeroes in 2432902008176640000 or 20!

# "20\n"
n =
  IO.gets("Input a number: ")
  # "20"
  |> String.trim()
  # 20
  |> String.to_integer()

# There are no recursive anon functions, so it needs to be an module
defmodule Factorial do
  def find(1), do: 1
  def find(n) when is_integer(n), do: n * find(n - 1)
end

# 20! = 20 * 19 * 18 * ... * 1 = 2432902008176640000
n_factorial = Factorial.find(n)

zeroes =
  n_factorial
  # "2432902008176640000"
  |> Integer.to_string()
  # ["2","4","3", ..., "0"]
  |> String.split("")
  # Iterate through the list
  |> Enum.reduce(0, fn
    # If it finds a 0, add 1 to the count
    "0", acc -> acc + 1
    # Else, skip
    _other, acc -> acc
  end)

# Reply to the user
IO.puts("There are #{zeroes} zeroes in #{n_factorial} or #{n}!")
