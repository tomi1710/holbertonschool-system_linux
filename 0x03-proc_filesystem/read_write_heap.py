#!/usr/bin/python3
""" Made by Tomas de Castro for Holberton School 2021"""
from sys import argv


def loop():
    """ aa """
    try:
        salida = 1
        (pid, string, new) = cambiar_formato()
        modificar_file(pid, string, new)
        salida = 0

    except Exception as e:
        print(e)
    finally:
        exit(salida)

def modificar_file(pid, string, new):
    """ aa """
    mapa = "/proc/{:d}/maps".format(pid)
    memoria = "/proc/{:d}/mem".format(pid)
    heap = "[heap]"
    dict = {"start": None, "end": None, "perms": None}

    with open(mapa, "r") as mapa, open(memoria, "rb+") as memoria:
        for line in mapa:
            if heap in line:
                print("[*] Found heap")
                tmp = line.split(" ")
                direccion = tmp[0].split("-")
                dict["start"] = int(direccion[0], 16)
                dict["end"] = int(direccion[1], 16)
                dict["perms"] = tmp[1]
                break

        if dict["perms"][:2] != "rw":
            raise PermissionError

        memoria.seek(dict["start"])
        content = memoria.read(dict["end"] - dict["start"])
        index = content.index(bytes(string, "ASCII"))
        print(content + "\n[*] Found string\n[*] Replacing string")
        memoria.seek(dict["start"] + index)
        memoria.write(bytes(new + "\0", "ASCII"))

def cambiar_formato():
    """ aa """
    pid = int(argv[1])
    string = argv[2]
    sig = argv[3]
    if len(sig) > len(string):
        raise IndexError

    return pid, string, sig


if __name__ == '__main__':
    loop()
