def main():
    camelCase = input("camelCase: ")
    snake_case = ''

    for i in range(0, len(camelCase)):
        if camelCase[i].isupper() == True:
            snake_case = snake_case + '_' + camelCase[i].lower()
        else:
            snake_case = snake_case + camelCase[i]

    print(f"snake_case: {snake_case}")


main()
