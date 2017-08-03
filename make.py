#!/usr/bin/env python

def main():
    import os
    os.system("g++ cov.cpp Matrix.cpp Vector.cpp")
    return 0

if __name__ == "__main__":
    import sys
    sys.exit(main())
