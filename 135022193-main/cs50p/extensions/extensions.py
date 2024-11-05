def main():
    imageType = ["gif", "png"]
    jpegType = ["jpg", "jpeg",]
    applicationType = ["pdf", "zip"]
    textType = ["txt"]

    name = input("File name: ").lower().strip()

    check = name.split(".")


    if check[-1] in jpegType:
        print(f"image/jpeg")
    elif check[-1] in imageType:
        print(f"image/{check[-1]}")
    elif check[-1] in applicationType:
        print(f"application/{check[-1]}")
    elif check[-1] in textType:
        print(f"text/plain")
    else:
        print("application/octet-stream")


main()
