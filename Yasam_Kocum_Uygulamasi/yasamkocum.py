import streamlit as st
import pandas as pd 

Determination = [
'You can’t break a man the way you break a dog, or a horse. The harder you beat a man, the taller he stands. - Far Cry 2',
'The moment you close your eyes on the battlefield is the moment you never open them again. - Metal Gear Solid 3: Snake Eater',
'I ve struggled a long time with surviving, but no matter what you have to find something to fight for. - The Last Of Us',
'Don t wish it were easier, wish you were better. - Animal Crossing',
'Do, or do not. There is no try. - Yoda, Star Wars',
'We Shall Never Surrender. - Soldier, Dunkirk',
'The only failure is not to try. - George Clooney',
'Don’t just fly, soar. - Dumbo',
'You control your destiny — you dont need magic to do it. And there are no magical shortcuts to solving your problems. - Merida, Brave',
'Why do we fall, sir? So that we can learn to pick ourselves up. - Alfred Pennyworth',
'The worst enemy to creativity is self-doubt. - — Sylvia Plath, The Unabridged Journals of Sylvia Plath',
'The problem is not the problem. The problem is your attitude about the problem. - Captain Jack Sparrow, Pirates of the Caribbean',
'I ll keep fighting. I ll keep swinging  til I got nothing left. - Dean Winchester, Supernatural',
'I have not failed. I ve just found 10,000 ways that won t work. - Thomas A. Edison',
]
Love = [
'The greatest thing you’ll ever learn is just to love and be loved in return. - Moulin Rouge',
'Love is blind, Wade. - Blind Al, Deadpool',
'Love means never having to say you’re sorry. - Jennifer Cavilleri, Love Story',
'When you realize you want to spend the rest of your life with somebody, you want the rest of your life to start as soon as possible. - When Harry Met Sally',
'To be brave is to love someone unconditionally, without expecting anything in return. - Madonna',
'You know you re in love when you can t fall asleep because the reality is finally better than your dreams. - Dr. Seuss',
'I love being married. It s so great to find one special person you want to annoy for the rest of your life. - Rita Rudner',
'When we love, we always strive to become better than we are. When we strive to become better than we are, everything around us becomes better too. - Paulo Coelho, The Alchemist',
'Sometimes it s a form of love just to talk to somebody that you have nothing in common with and still be fascinated by their presence. - David Byrne',
'The greatest happiness of life is the conviction that we are loved; loved for ourselves, or rather, loved in spite of ourselves. - Victor Hugo',
'It is a curious thought, but it is only when you see people looking ridiculous that you realize just how much you love them. - Agatha Christie, An Autobiography',
'Gravitation is not responsible for people falling in love. - Albert Einstein',
'I m not saying that love always takes you to heaven. Your life can become a nightmare. But that said, it is worth taking the risk. - Paulo Coelho',
'Truth is everybody is going to hurt you: you just gotta find the ones worth suffering for. - Bob Marley',
'We are afraid to care too much, for fear that the other person does not care at all. - Eleanor Roosevelt'
]
Life = [
'If our lives are already written, it would take a courageous man to change the script. - Alan Wake.',
'Some trees flourish, others die. Some cattle grow strong, others are taken by wolves. Some men are born rich enough and dumb enough to enjoy their lives. Ain t nothing fair. You know that. - John Marston, Red Dead Redemption.',
'Stand amongst the ashes of a trillion dead souls, and ask the ghosts if honor matters. The silence is your answer. - Mass Effect 3.',
'Nothing is True, Everything is Permitted. - Assasin s Creed 1.',
'We all make choices, but in the end... our choices make us. - Andrew Ryan, Bioshock.',
'Life is a negotiation. We all want. We all give to get what we want. - Mass Effect 2',
'To say that everything is permitted is to understand that we are the architects of our actions and that we must live with our consequences, whether glorious or tragic. - Ezio, Assassins Creed: Revelations',
'Human beings can choose the kind of life that they want to live. What s important is that you choose life... and then live. - Metal Gear Solid',
'Life is a serious battle, and you have to use the tools you re given. - Pokemon Black And White',
'Oh yes, the past can hurt. But you can either run from it, or learn from it. - Rafiki, Lion King',
'The goal isn’t to live forever, the goal is to create something that will. - Chuck Palahniuk, Diary',
'You make your own luck. - Harvey Dent, The Dark Knight',
'Live long and prosper. - Spock, Star Trek',
'Life is like an onion. You peel it off one layer at a time, and sometimes you weep. - Carl Sandburg',
]
Hope  = [
'Hope is what makes us strong. It is why we are here. It is what we fight with when all else is lost. - God Of War 3',
'Hope. It is the only thing stronger than fear. A little hope is effective. A lot of hope is dangerous. A spark is fine, as long as it s contained. - President Snow, The Hunger Games',
'Once you choose hope, anythings possible. - Christopher Reeve',
'There is some good in this world, and it s worth fighting for. - J.R.R. Tolkien',
'I don t think of all the misery, but of the beauty that still remains. - Anne Frank',
'Most of the important things in the world have been accomplished by people who have kept on trying when there seemed to be no hope at all. - Dale Carneige',
'We must accept finite disappointment, but never lose infinite hope. - Martin Luther King Jr.',
'However bad life may seem, there is always something you can do and succeed at. Where there s life, there s hope. - Stephen Hawking',
'Hope is important because it can make the present moment less difficult to bear. If we believe that tomorrow will be better, we can bear a hardship today. - Thich Nhat Hanh',
'Far away there in the sunshine are my highest aspirations. I may not reach them but I can look up and see their beauty, believe in them, and try to follow them. - Louisa May Alcott',
'Even the darkest night will end and the sun will rise. - Victor Hugo, Les Miserables',
]
Courage = [
'A sword wields no strength unless the hands that holds it has courage. - Legend of Zelda: Twilight Princess',
'Courage need not be remembered, for it is never forgotten!. - The Legend Of Zelda: Breath Of The Wild',
'The courage to walk into the darkness, but strength to return to the light. - Destiny',
'What is bravery, without a dash of recklessness?. - Dark Souls',
'You can’t undo what you’ve already done, but you can face up to it. - Silent Hill: Downpour',
'All the courage in the world cannot alter fact. - Niander Wallace, Blade Runner 2049',
'Fortune favors the bold. - im Miami Beach, Bohemian Rhapsody',
'The hardest choices require the strongest wills. - Thanos, The Avengers',
'Some people can never believe in themselves until someone believes in them. - Good Will Hunting',
'Be brave to stand for what you believe in even if you stand alone. - Roy T. Bennett, The Light in the Heart',
'Fear doesn’t shut you down; it wakes you up. - Veronica Roth, Divergent',
'I must not fear. Fear is the mind-killer. - Paul Atreides, Dune',
'You only get one chance at life and you have to grab it boldly. - Bear Grylls',
]
category = ['Determination'] * len(Determination) + ['Love'] * len(Love) + ['Life'] * len(Life) + ['Hope'] * len(Hope) + ['Courage'] * len(Courage)
quotes = Determination + Love + Life + Hope + Courage
quotes_data = pd.DataFrame({'quotes': quotes, 'category': category})

def give_advice(choice):
    if choice != 'Random':
        x = quotes_data[quotes_data.category == choice]
        sentence1 = x.quotes.sample(n = 1).values[0]
        sentence2 = sentence1.replace(' - ', '\n - ')
    else:
        sentence1 = quotes_data.quotes.sample(n = 1).values[0]
        sentence2 = sentence1.replace(' - ', '\n - ')
    return(sentence2)
    
        
def jaccard_similarity(str, ans):
    str = set([i.lower() for i in str.split()])
    ans = set([j.lower() for j in ans.split()])
    return float(len(str.intersection(ans)) / len(str.union(ans)))
    
def listen_give_advice(c):
    similarity_ratios = quotes_data.quotes.apply(lambda s: jaccard_similarity(s, c))
    st_inorder = similarity_ratios.sort_values(ascending = False).index
    most_similar = quotes_data.iloc[st_inorder[0]].quotes
    return(most_similar)    

st.set_page_config(page_title= 'Old&Wise Binary Script')
st.title('`O The Wise Binary Code')
st.subheader('Share your wisdom...')
st.image("https://c.tenor.com/d_F0vFJFxtsAAAAC/kill-bill-pai-mei.gif")

choose_me = st.selectbox('Choose your category:', ['Determination', 'Love', 'Life', 'Hope', 'Courage', 'Random'])
button1 = st.button('Get sum advice.')
if button1:
    st.write(give_advice(choose_me))
    
strng = st.text_input('What`s on your mind?')
if strng != '':
    st.write(listen_give_advice(strng).replace(' - ', '\n - '))



