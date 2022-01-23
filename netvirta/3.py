#!/bin/python3

import sys
import os
from urllib import response
from urllib.request import Request
from urllib.request import urlopen
from urllib.error import URLError
import json
import pprint as pp

# Complete the function below.
# Base url: https://jsonmock.hackerrank.com/api/movies/search/?Title=

BASE_URL = "https://jsonmock.hackerrank.com/api/movies/search/?Title="


def fetchDataHandler(url):
    request = Request(url)
    response = urlopen(request).read().decode("utf-8")
    json_data = json.loads(response)
    return json_data


def getMovieTitles(substr):
    title_url = BASE_URL + substr
    # JSON response field identifiers
    kTotalPages = "total_pages"
    kData = "data"
    kTitle = "Title"

    # Fetch data from first page
    all_data = fetchDataHandler(title_url)
    total_pages = all_data.get(kTotalPages)
    data = all_data.get(kData)

    # Fetch more data from other pages if needed, 1-indexed inclusive
    for page in range(2, total_pages + 1):
        title_page_url = title_url + "&page=" + str(page)
        all_data = fetchDataHandler(title_page_url)
        data = data + all_data.get(kData)

    titles = sorted([record.get(kTitle) for record in data])
    return titles


# _substr = str(input())
_substr = "spiderman"
res = getMovieTitles(_substr)
for res_cur in res:
    print(str(res_cur))
