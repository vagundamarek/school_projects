class ExchangeRates:
    def __init__(self, filename):
        self.data = {"CZK": 1}
        f = open(filename, 'r')
        self.issued = f.readline().split()[0]
        for i in range(0, 3):
            f.readline()
            #skip lines without information
        for line in f:
            separated = line.split(";")
            self.data[separated[2]] = float(separated[6].replace(",", "."))/float(separated[1].replace(",", "."))
        f.close()

    def issue_date(self):
        return self.issued
    
    def convert_to_CZK(self, currency, amount):
        if self.data.get(currency) == None:
            print("Unknown currency: " + currency)
            return None
        return amount*self.data[currency]
                
    def convert_from_CZK(self, currency, amount):
        if self.data.get(currency) == None:
            print("Unknown currency: " + currency)
            return None
        return amount/self.data[currency]
        
    def convert_from_to(self, from_curr, to_curr, amount):
        return self.convert_from_CZK(to_curr, self.convert_to_CZK(from_curr, amount))

def isFloat(s):
    try:
        float(s)
        return True
    except ValueError:
        return False
    
#does accept floats with decimal point
def main():
    rates = ExchangeRates("kurzy.csv")
    print("Exchange rates for "+rates.issue_date())
    while True:
        print("Exchange: ", end="")
        command = input()
        if command == "stop":
            return
        separated = command.split()
        if len(separated) != 4 or isFloat(separated[0])== False or separated[2] != "to":
            print ("Unknown command or wrong command format.")
        else:
            amount = float(separated[0])
            x = rates.convert_from_to(separated[1], separated[3], amount)
            if x != None:
                print ("{0:.2f}".format(amount)+" "+separated[1]+" = " + "{0:.2f}".format(x) + " " + separated[3])
