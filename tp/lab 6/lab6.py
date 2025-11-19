class Product:
    id = 0

    def __init__(self, name, stock, price):
        self.name = name
        self.stock = stock
        self.price = price
        self.count = Product.id
        Product.id += 1

    def restock(self):
        print('1. if you want to add product\n2. if you want to remove product')
        choice = input()
        if choice == '1':
            print('How many products do you want to add?')
            choice = int(input())
            self.stock += choice
        if choice == '2':
            print('How many products do you want to remove?')
            choice = int(input())
            if choice < self.stock:
                self.stock -= choice
                print('success')
            else:
                print('not allowed , out of volume!')
                pass
        else:
            pass


class Buyer:
    total_orders = 0
    def __init__(self, name, shopping_cart ):
        self.name = name
        self.shopping_cart = [shopping_cart,] if shopping_cart != '' else []
    def add_product(self):
        print('What product do you want to add?')
        i=0
        for product in instances:
            print(i,". ",product.name)
            i+=1
        del(i)
        choice = int(input())
        if (choice != ''):
            print('How many products do you want to add?')
            choice2 = int(input())
            if (0<=choice<len(instances)):
                products = instances[choice]
                if (0<=choice2<=int(products.stock)):
                    products.stock -= choice2
                    instances[choice] = products
                    self.shopping_cart.append(str(products.name)+'//'+str(choice2))
                else:
                    print('not allowed , out of volume!')
    def remove_product(self):
        if (self.shopping_cart != []):
            print('What product do you want to remove?')
            i = 0
            for product in self.shopping_cart:
                print(i, ". ", product)
                i += 1
            del (i)
            choice = int(input())
            print('How much product do you want to remove?')
            choice2 = int(input())
            if (0 <= choice <= len(instances)):
                products = instances[choice]
                if (0<=choice2<=int(products.stock)):
                    a = str(self.shopping_cart[choice]).split('//')
                    if (int(a[1])<int(choice2)):
                        print('not allowed , out of volume!')
                        pass
                    else:
                        products.stock += choice2
                        instances[choice] = products
                        self.shopping_cart[choice] = a[0]+'//'+str(int(a[1])-choice2)
    def pricing(self):
        price = 0
        for item in self.shopping_cart:
            if isinstance(item, str):
                product_name, quantity = item.split('//')
                for prod in instances:
                    if prod.name == product_name:
                        price += prod.price * int(quantity)
        return price

    order_completed = False
    def complite_order(self):
        if not self.order_completed:
            print("Заказ клиента",self.name,"завершён.")
            self.order_completed = True
            Buyer.total_orders += 1
        else:
            print("Заказ клиента",self.name,"уже завершён.")
            order_completed = False

    @classmethod
    def all_orders(cls):
        return cls.total_orders


class SpecialbyBuyer(Buyer):
    def __init__(self, name, shopping_cart):
        super().__init__(name, shopping_cart)
        self.base_price = 0

    def add_product(self):
        return super().add_product()

    def remove_product(self):
        return super().remove_product()

    def pricing(self):
        self.base_price = super().pricing()
        return self.base_price * 0.9

    def complite_order(self):

        if not self.order_completed:
            print("Премиум-заказ клиента",self.name,"успешно завершён со скидкой 10%.")
            self.order_completed = True
            Buyer.total_orders += 1
        else:
            print("Премиум-заказ клиента",self.name,"уже завершён.")








def change():
    print('Enter the name of product you want to change:')
    choice = input()
    for product in instances:
        if product.name == choice:
            product.restock()

def mainbuyer():
    print('do you are special buyer? y/n ')
    choice = input()
    if choice == 'y':
        name = input('enter your name ')
        buyer = SpecialbyBuyer(name,'')
    else:
        name = input('enter your name ')
        buyer = Buyer(name , '')

    while (True):
        print('1. To view catalog')
        print('2. To put some in shopping cart')
        print('3. To remove some from shopping cart')
        print('4. To make purchare')
        print('5. To exit the application')
        choice = input()
        match choice:
            case '1':
                for products in instances:
                    print('-',products.name,'\t\tin stock - ', products.stock,'\t   price-', products.price)

            case '2':
                buyer.add_product()

            case '3':
                buyer.remove_product()

            case '4':
                price = buyer.pricing()
                print('costs - ',price)
                print('You confirm purchare? y/n')
                choice = input()
                if choice == 'y':
                    buyer.complite_order()
                    break
                if choice == 'n':
                    pass
            case '5':
                break

instances = [Product('banana',64,100),
Product('apple',64,100),
Product('meat',64,100),
Product('milk', 42, 85),
    Product('bread', 73, 40),
    Product('cheese', 58, 150),
    Product('butter', 37, 120),
    Product('yogurt', 91, 60),
    Product('orange', 67, 95),
    Product('grape', 33, 200),
    Product('pear', 55, 110),
    Product('peach', 48, 130),
    Product('cherry', 28, 220),
    Product('strawberry', 44, 180),
    Product('blueberry', 39, 210),
    Product('watermelon', 25, 300),
    Product('melon', 29, 250),
    Product('pineapple', 33, 270),
    Product('kiwi', 46, 140),
    Product('mango', 41, 230),
    Product('papaya', 31, 190),
    Product('coconut', 27, 260),
    Product('lemon', 63, 90),
    Product('lime', 52, 85),
    Product('carrot', 78, 50),
    Product('potato', 99, 35),
    Product('onion', 82, 40),
    Product('garlic', 69, 60),
    Product('tomato', 74, 55),
    Product('cucumber', 88, 45),
    Product('pepper', 59, 70),
    Product('eggplant', 38, 95),
    Product('zucchini', 42, 85),
    Product('broccoli', 57, 120),
    Product('cauliflower', 61, 110),
    Product('spinach', 50, 65),
    Product('lettuce', 66, 75),
    Product('cabbage', 70, 55),
    Product('pumpkin', 28, 140),
    Product('corn', 35, 80),
    Product('rice', 92, 60),
    Product('pasta', 85, 70),
    Product('flour', 99, 50),
    Product('sugar', 84, 45),
    Product('salt', 95, 25),
    Product('oil', 53, 130),
    Product('vinegar', 47, 90),
    Product('coffee', 62, 160),
    Product('tea', 77, 120),
    Product('juice', 68, 100),
    Product('water', 100, 30),
    Product('soda', 80, 70),
    Product('beer', 52, 150),
    Product('wine', 36, 400),
    Product('whiskey', 22, 900),
    Product('vodka', 31, 300),
    Product('rum', 19, 850),
    Product('gin', 26, 780),
    Product('champagne', 17, 950),
    Product('chocolate', 75, 120),
    Product('candy', 82, 60),
    Product('cookies', 90, 70),
    Product('cake', 32, 250),
    Product('pie', 40, 210),
    Product('ice_cream', 55, 140),
    Product('chips', 79, 80),
    Product('popcorn', 64, 50),
    Product('nuts', 46, 180),
    Product('almonds', 34, 200),
    Product('cashews', 29, 220),
    Product('peanuts', 71, 90),
    Product('raisins', 43, 100),
    Product('honey', 37, 160),
    Product('jam', 51, 130),
    Product('sauce', 49, 110),
    Product('ketchup', 73, 90),
    Product('mustard', 67, 85),
    Product('mayonnaise', 58, 95),
    Product('soup', 54, 75),
    Product('noodles', 83, 70),
    Product('sausage', 61, 180),
    Product('bacon', 47, 200),
    Product('ham', 44, 220),
    Product('fish', 36, 240),
    Product('salmon', 33, 300),
    Product('tuna', 39, 260),
    Product('shrimp', 25, 340),
    Product('crab', 21, 420),
    Product('lobster', 18, 600),
    Product('egg', 97, 50),
    Product('buttermilk', 63, 80),
    Product('cream', 40, 130),
    Product('tofu', 52, 100),
    Product('beans', 72, 90),
    Product('lentils', 85, 95),
    Product('peas', 79, 85),
    Product('oats', 88, 75),
    Product('cereal', 93, 110),
    Product('granola', 66, 120),
    Product('protein_bar', 48, 150),
    Product('energy_drink', 56, 180),
    Product('toothpaste', 70, 60),
    Product('soap', 82, 40),
    Product('shampoo', 64, 130),
    Product('detergent', 58, 150),
    Product('tissue', 95, 35),
    Product('battery', 50, 200)
             ]
while True:
    choice = int(input('1. If you are buyer\n2. If you are admin of shop and want '
                   'to change volume of products\n3. if you wont to exit\n-->'))
    if choice == 1:
        mainbuyer()
    if choice == 2:
        change()
    if choice == 3:
        break



