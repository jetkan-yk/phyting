from string import ascii_lowercase


def getAvailableLetters(lettersGuessed):
    """
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters that represents what letters have not
      yet been guessed.
    """
    return "".join([x for x in ascii_lowercase if x not in lettersGuessed])
