#!/usr/bin/python3
"""Count It"""
import requests


def count_words(subreddit, word_list, hot_titles=[], after='null'):
    """parses the title of all hot articles"""
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT/5.1;Win64,x64)'}
    res = requests.get('https://www.reddit.com/r/' +
                       subreddit + '/hot.json',
                       headers=headers,
                       params={"limit": "100", "after": after},
                       allow_redirects=False)
    if res.status_code != 200:
        return None

    for i in res.json().get('data').get('children'):
        hot_titles.append(i.get('data').get('title'))
    after = res.json().get('data').get('after')

    if after is None:
        word_dict = {w: 0 for w in word_list}
        for w in word_list:
            c = 0
            for t in hot_titles:
                c += [i.lower() for i in t.split()].count(w.lower())
            word_dict[w] += c

        for i, c in sorted(word_dict.items(), key=lambda x: x[1],
                           reverse=True):
            if c != 0:
                print("{}: {}".format(i, c))
    else:
        return count_words(subreddit, word_list, hot_titles, after)