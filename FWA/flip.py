import sys
import pefile
import win32api
import win32file
import codecs
import argparse
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

def bytes_from_file_iter(filename, chunksize=8192):
    with open(filename, "rb") as f:
        while True:
            chunk = f.read(chunksize)
            if chunk:
                for b in chunk:
                    yield b
            else:
                break

def main():

    file_attributes(args.arch)
    for _byte in bytes_from_file_iter(args.file):
        print(hex(_byte))



if __name__ == "__main__":
    main()