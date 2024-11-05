from bs4 import BeautifulSoup
import requests
import time


def amazon_scraper(URL):
    page = requests.get(URL)

    soup = BeautifulSoup(page.content, 'lxml')

    # Look for the current price
    spans = soup.find('span', class_="a-price-whole")
    if spans == None:
        # CHECK THIS
        print("Too many requests, try again later OR something is wrong")
        return 1

    currentPrice = spans.text.replace("\n", '')
    # error maybe possibly in future
    currentPrice = currentPrice.replace('-','00').replace("\u2013","").replace("  ", '.')

    # Look for original price
    ogPrice = soup.find('del', class_="a-offscreen")
    if ogPrice != None:
        ogPrice = ogPrice.text
        ogPrice = ogPrice.replace(",", ".")
        ogPrice = ogPrice.replace('-','00').replace("\u2013","")
    else:
        ogPrice = currentPrice

    # Make sure theres no weird symbol in the price, if there is print the price
    try:
        savings = float(ogPrice) - float(currentPrice)
    except ValueError:
        print(ogPrice)
        print(currentPrice)
        return 0
    savings = round(savings, 2)
    savings = str(savings)

    dictValues = {
        "name": soup.title.text,
        "ogPrice": ogPrice,
        "currentPrice": currentPrice
    }
    return dictValues


def main():
    dictValues = amazon_scraper("https://www.amazon.nl/Robotstofzuigers-Robotstofzuiger-Dweilfunctie-Automatische-Zelfopladende/dp/B092ZPSBJM?ref=dlx_deals_dg_dcl_B092ZPSBJM_dt_sl14_75")
    print(dictValues)
    time.sleep(2)

main()
