import sys
import pefile
import win32api
import win32file
import codecs
import argparse
from bitstring import BitArray
parser = argparse.ArgumentParser()
parser.add_argument("-f", "--file", help="The file to mutate", required = True)
parser.add_argument("-a", "--arch", help="The file's architecture, x86 or x64'", required = True)
parser.add_argument("-c", "--chunksize",  help = "Chunksize to read of the file's bytes")
args = parser.parse_args()

def file_attributes(arch):
    if arch == "x86":
        return "x86"

    if arch == "x64":
        return "x64"

    raise Exception("Architecture not supported")

def main():
    file_attributes(args.arch)
    _f = open(args.file).read()
    ' '.join(format(ord(x), 'b') for x in _f)


if __name__ == "__main__":
    main()