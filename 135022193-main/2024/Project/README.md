# Discount Checker
#### Video Demo:  [Video](https://www.youtube.com/watch?v=pI1Q5ycwxfg&ab_channel=NordinSchoenmakers)
#### Description:
The purpose of my website Discount Checker is to have a website where you can check if any of your
favorite products are on sale. We all know the pain of buying something and 2 days later it has a
massive sale, or you have too many products you want to keep tabs on each one of them.
My project aims to simplify that process, it is by no meansthe final 1.0 release but getting there
would take alot of time and quite alot of money as well. However in its current state is works
exactly how i wanted it to work and it works almost flawlessly(sometimes the server is a bit buggy)
on the biggest webshop in the netherlands: bol.com. You simply put in the URL of an item you want
to keep your eyes on and the website will automatically get the current price, original price
and calculate the amount of money you'll be saving, when you hit the refresh button all products will
be rechecked and the prices will be updated if they have changed. You can also click on the name of the
product to go to the URL of the product. Every user has their own individual list so you wont have
the problem that someone elses products will end up on your list.

The scrapers.py file holds 2 functions currently however only one is in use. The first one bol_scraper() is
the one thats in use and is used for bol.com. The second one amazon_scraper() is not in use, the reason for
this is that amazon has anti scraping technology in use and i would need a proxy to get it to work well
it does actually work and ive gotten the desired output however its too inconsistent to implement without
a proxy which would cost money. The app.py file contains the most important parts, almost all of the
back-end of the website, most of it is not that special, but one i would like to /api/get_prices, this
function works together with a JS script in index.html to refresh the table when a refresh button is
clicked. The reason i want to bring attention to this function in specific is because it was the hardest
part of the project by far. I was a massive beginner with javascript when i started this project, however
i did want my website to have a nice smooth user experience so dynamically updating the table was a must
for me, however i quickly learned javascript is a very weird language compared to anything ive learned
before, it took me alot of frustration and more trail and error than i can count to get such a simple and
small function to work the way i wanted it to but i can confidently say i got it done just the way i wanted
it to(With a little help of our beloved duck ofcourse). I also found out how many little details go into a
website so simple, its almost like 90% of this Project was spent catching bugs and figuring out how to make
sure they dont happen again or making an appropriate response to them happening. Sadly I couldnt show all
I did in the 3 minutes of the video but an example is the URL input, I found out when you give it a wrong
URL it wouldnt give u good looking error or apology, it would just give you an automated error page which
I did not like at all so I spent a good hour analysing and trying out every possible link someone could put
in thats not a correct product URL and catching every one of them in a small function thats not hundreds
of if statements and I think i did a pretty good job. I also put quite a bit of effort into making the
website look nice without excessive use of bootstrap, I am personally not the biggest fan of bootstrap due
to how difficult it sometimes is to edit a bootstrap example, so I put extra effort into making my own
buttons, text inputs and only used bootstrap for the navigation bar and the table but one day I am going to
make my own navigation bar and table for this website and replace the bootstrap examples. As a final word in
this paragraph I'd like to say that i made sure to use what I have learned from CS50, not just using
html/css, python, SQL etc. but also the problem solving mindset, to not just give up and to keep looking for
an answer and to make sure my code is well designed and doesnt smell weird. I always try to make my code as
clean as possible and to make sure theres no copy paste going on or duplicate functions, I can definitely
say that i have figured out im a bit of a perfectionist but it makes getting it just right all the more
sweeter.

This project has been in my mind for about 4 months now and the webscraper used has been in my hard drive
for the same amount of time and i feel super happy now that i finally brought my idea somewhat to life.
I also wont stop working on it after i turn it in,
it has become a passion project of mine and i hope to one day make it work on alot of major webshops
and give public access to it so anyone can use it. I hope my project has showcased what i have learned and
i would like to thank everyone that has worked on CS50 for giving this amazing introduction to
computer science and helping me discover my love for programming.
