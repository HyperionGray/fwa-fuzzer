import sys
import pefile

def main():

    pe =  pefile.PE(sys.argv[1])
    print(pe.OPTIONAL_HEADER)



if __name__ == "__main__":
    main()