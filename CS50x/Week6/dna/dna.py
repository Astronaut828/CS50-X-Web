import csv
import sys

databases = list()
sequences = list()


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Incorrect usage")
        return

    # Read database file into a variable
    with open(sys.argv[1]) as f:
        reader = csv.DictReader(f)
        # Get the list of STRs from the first row of the CSV file
        strs = reader.fieldnames[1:]
        for row in reader:
            databases.append(row)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as f:
        sequences = csv.reader(f)
        sequence_str = ''.join(next(sequences))

    # Find longest match of each STR in DNA sequence
    matches = []
    for str in strs:
        match = longest_match(sequence_str, str)
        matches.append(match)

    # Check database for matching profiles
    for row in databases:
        # Check if all matches match the values in the row
        if all(matches[i] == int(row[strs[i]]) for i in range(len(strs))):
            print(row['name'])
            return

    # If no match is found, print "No match"
    print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
