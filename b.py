import nltk, string, random
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

# 1. Download NLTK data once
nltk.download('punkt', quiet=True)
nltk.download('wordnet', quiet=True)

# 2. Knowledge base: simple FAQ list
FAQ = [
    ("what are your hours", "We’re open 9 AM–6 PM Mon–Sat."),
    ("how do i return an item", "Go to Orders → click ‘Return’ next to the item."),
    ("how can i track my order", "Enter your order ID on the Track page."),
    ("what payment methods do you accept", "We accept cards, UPI, and net‑banking."),
    ("roshan vikas patil","he is pict student")
]

# 3. Preprocess & helper functions
lemmer = nltk.stem.WordNetLemmatizer()
def normalize(text):
    text = text.lower().translate(str.maketrans('','',string.punctuation))
    return [lemmer.lemmatize(tok) for tok in nltk.word_tokenize(text)]

# 4. Greeting detection
GREET_IN = {"hi","hello","hey"}
GREET_OUT = ["Hi there!", "Hello!", "Hey! How can I help?"]
def check_greeting(s):
    for w in s.split():
        if w.lower() in GREET_IN:
            return random.choice(GREET_OUT)
    return None

# 5. TF–IDF setup
questions = [q for q,a in FAQ]
tfidf_vec = TfidfVectorizer(tokenizer=normalize, stop_words='english')
tfidf_matrix = tfidf_vec.fit_transform(questions)

# 6. Generate answer
def answer(user):
    # 6.1 greeting?
    g = check_greeting(user)
    if g: return g

    # 6.2 FAQ retrieval
    user_tfidf = tfidf_vec.transform([user])
    sims = cosine_similarity(user_tfidf, tfidf_matrix).flatten()
    idx = sims.argmax()
    if sims[idx] < 0.2:
        return "Sorry, I didn't understand. Can you rephrase?"
    return FAQ[idx][1]

# 7. Chat loop
def chat():
    print("CatBoat: Hello! Type 'bye' to exit.")
    while True:
        u = input("You: ").strip()
        if u.lower() == 'bye':
            print("CatBoat: Goodbye!"); break
        print("CatBoat:", answer(u))

if __name__ == "__main__":
    chat()
