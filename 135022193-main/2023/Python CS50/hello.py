with open("romeo.txt", "r") as file:
    with open("juliet.txt", "w") as file2:
        for line in file:
                file2.write(line.replace("the ", "the penis "))
file.close()
