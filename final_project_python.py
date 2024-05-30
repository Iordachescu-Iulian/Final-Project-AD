import random

def main():
    random.seed()

    choice = int(input("Choose an option:\n1. Manual input of book sizes\n2. Randomly generate book sizes\n"))

    if choice == 1:
        # Manual input
        total_books = int(input("Insert the amount of books you want: "))
        print("Now for the number of pages for each book. For simplicity and ease of use, you will need to input just one or more numbers which will then be multiplied by 100.")
        books = [int(input(f"Book[{i + 1}]: ")) * 100 for i in range(total_books)]
    elif choice == 2:
        # Randomly generate book sizes
        total_books = random.randint(1, 19)  # Random amount of books (maximum 19)
        books = [random.randint(100, 1099) for _ in range(total_books)]  # Random sizes between 100 and 1099
    else:
        print("Invalid choice. Please choose 1 or 2.")
        return 1  # Exit program if choice is invalid

    num_employees = int(input("Enter the number of employees: "))
    total_pages = sum(books)
    avg_pages = total_pages // num_employees

    current_sum = 0
    sections = 1

    print("Employee 1:", end=" ")

    for book in books:
        current_sum += book
        if current_sum > avg_pages * sections:
            print(f"\nEmployee {sections + 1}:", end=" ")
            sections += 1
        print(book, end=" ")

    print(f"\nAverage pages per employee: {avg_pages}")

if __name__ == "__main__":
    main()