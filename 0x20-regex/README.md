Write a function that checks whether a given pattern matches a given string.

    Prototype: int regex_match(char const *str, char const *pattern);, where:
        str is the string to scan
        pattern is the regular expression
    Your function must return 1 if the pattern matches the string, or 0 if it doesn’t
    str can be empty, and can contain any ASCII character in the exception of . and *
    pattern can be empty, and can contain any ASCII character, including . and *
    The regular expression matching must support the characters . and *
        . matches any single character
        * matches zero or more of the preceding character
