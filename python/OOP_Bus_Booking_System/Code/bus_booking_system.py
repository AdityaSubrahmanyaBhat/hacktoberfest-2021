class BusBooking :

    def __init__(self):

        self.current_seat = {

            1 : False,
            2: False,
            3: False,
            4: False,
            5: False,
            6: False,
            7: False,
            8: False,
            9: False,
            10: False

        }

    def book_seat(self, name, seat):

        if seat <= 10 :

            if self.current_seat[seat] == False :
                self.current_seat[seat] = name
                print("Seat succesfully booked !")
            else:
                print("Seat already booked ! Please book another one")



        else:
            print("Please enter a valid seat number between 1 and 10 !")

    def remove_seat(self, seat):

        if seat <= 10 :
            if self.current_seat[seat] != False :

                name = self.current_seat[seat]

                check = input("Are you sure you want to delete seat no. {} booked by {} ? (Y/N) : ".format(seat, name))

                if check == 'Y' :
                    self.current_seat[seat] = False
                    print("Seat successfully removed !")

                elif check == 'N' :
                    print("Seat Removal Cancelled")

                else:
                    print("Please enter Y or N")



            else:
                print("This seat is already empty ! Please recheck your seat number !")



        else:
            print("Please enter a valid seat number between 1 and 10 !")

    def display(self) :

        print("\nThis is the current bus : \n")

        if self.current_seat[1] != False:
            s1 = 'SB'
        else:
            s1 = '01'

        if self.current_seat[2] != False:
            s2 = 'SB'
        else:
            s2 = '02'

        if self.current_seat[3] != False:
            s3 = 'SB'
        else:
            s3 = '03'

        if self.current_seat[4] != False:
            s4 = 'SB'
        else:
            s4 = '04'

        if self.current_seat[5] != False:
            s5 = 'SB'
        else:
            s5 = '05'

        if self.current_seat[6] != False:
            s6 = 'SB'
        else:
            s6 = '06'

        if self.current_seat[7] != False:
            s7 = 'SB'
        else:
            s7 = '07'

        if self.current_seat[8] != False:
            s8 = 'SB'
        else:
            s8 = '08'

        if self.current_seat[9] != False:
            s9 = 'SB'
        else:
            s9 = '09'

        if self.current_seat[10] != False:
            s10 = 'SB'
        else:
            s10 = 10

        print('   -----   ')
        print('   |   |   ')
        print('-----------')
        print('| {} | {} |'.format(s1, s2))
        print('| {} | {} |'.format(s3, s4))
        print('| {} | {} |                            (S.B --> Seat Booked)'.format(s5, s6))
        print('| {} | {} |'.format(s7, s8))
        print('| {} | {} |'.format(s9, s10))
        print('-----------\n\n')

Bus1 = BusBooking()

print('''

██████╗ ██╗   ██╗███████╗    ██████╗  ██████╗  ██████╗ ██╗  ██╗██╗███╗   ██╗ ██████╗     ███████╗██╗   ██╗███████╗████████╗███████╗███╗   ███╗
██╔══██╗██║   ██║██╔════╝    ██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝██║████╗  ██║██╔════╝     ██╔════╝╚██╗ ██╔╝██╔════╝╚══██╔══╝██╔════╝████╗ ████║
██████╔╝██║   ██║███████╗    ██████╔╝██║   ██║██║   ██║█████╔╝ ██║██╔██╗ ██║██║  ███╗    ███████╗ ╚████╔╝ ███████╗   ██║   █████╗  ██╔████╔██║
██╔══██╗██║   ██║╚════██║    ██╔══██╗██║   ██║██║   ██║██╔═██╗ ██║██║╚██╗██║██║   ██║    ╚════██║  ╚██╔╝  ╚════██║   ██║   ██╔══╝  ██║╚██╔╝██║
██████╔╝╚██████╔╝███████║    ██████╔╝╚██████╔╝╚██████╔╝██║  ██╗██║██║ ╚████║╚██████╔╝    ███████║   ██║   ███████║   ██║   ███████╗██║ ╚═╝ ██║
╚═════╝  ╚═════╝ ╚══════╝    ╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝ ╚═════╝     ╚══════╝   ╚═╝   ╚══════╝   ╚═╝   ╚══════╝╚═╝     ╚═╝
''')

print("Welcome to the bus booking CLI. This is an OOP based tool that can help you book tickets and cancel the bookings.\n\nType 'book' to book a seat and 'remove' to remove your booking. \n")

Bus1.display()

raw = input("What do you want to do ?\n-> ")

while raw != 'end' :

    if raw == 'book' :
        name = input("Enter your name : ")
        seat = int(input("Enter seat_no. that you want to book : "))

        Bus1.book_seat(name, seat)
        Bus1.display()
        raw = input("What do you want to do ?\n-> ")

    elif raw == 'remove' :

        seat = int(input("Enter seat no. : "))

        Bus1.remove_seat(seat)
        Bus1.display()
        raw = input("What do you want to do ?\n-> ")

    else:
        print("Please enter a valid command !")
        raw = input("What do you want to do ?\n-> ")

