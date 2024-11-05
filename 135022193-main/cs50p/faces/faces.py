def main():
    str = input()
    convert(str)



def convert(emote):
    print(emote.replace(":)", "🙂").replace(":(", "🙁"))

main()
