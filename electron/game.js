$(document).ready(() => {
    $.getJSON('https://raw.githubusercontent.com/words/an-array-of-english-words/master/words.json', (data) => {

        let startGame = () => {
            const marks = ["?", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "+", "-", "_", "=", "[", "]", "{", "}", "|", ",", ".", "'"];
            let startingMemoryAddress = 5440;
            let incrementer = 12;

            $('#password').append('<span>Password Required</span>');
            $('#attempts').append('Attempts Remaining: <span class="attempt"></span><span class="attempt"></span><span class="attempt"></span><span class="attempt"></span>');

            const memorySlots = $('.hex').toArray();

            // fill the leftmost columns with hex addresses
            for (let i = 0; i < memorySlots.length; i++) {
                memorySlots[i].textContent = '0x' + startingMemoryAddress.toString(16).toUpperCase();
                startingMemoryAddress += incrementer;
            }

            // collect words with 3 letters length
            const arrayOfEqualLengthWords_5 = [];
            for (let i = 0; i < 32;) {
                let word = data[Math.floor(Math.random() * (data.length - 1 - 0)) + 0];

                if (word.length != 5) {
                    continue;
                } else {
                    arrayOfEqualLengthWords_5.push(word);
                    i++;
                }
            }

            const textSlots = $('.text');

            // fill the window with marks and words
            let rowMaxWidth = 16;
            let currentWidth = 0;
            let wordLength = 5;
            let wordCounter = 0;
            let wordList = [];
            let wordLimit = 32;
            let wordCounterRow = 0;
            let wordLimitRow = 1;
            for (let i = 0; i < 32;) {
                let verdict = Math.floor(Math.random() * (4 - 0) + 0);

                if (verdict <= 2) {
                    if ((currentWidth + 1) <= rowMaxWidth) {
                        const mark = document.createTextNode(marks[Math.floor(Math.random() * (marks.length - 1 - 0)) + 0]);
                        textSlots[i].append(mark);
                        currentWidth++;
                    }
                } else if (verdict > 2) {
                    if ((currentWidth + wordLength) <= rowMaxWidth && wordCounter < wordLimit && wordCounterRow < wordLimitRow) {
                        // create word span element with text
                        const word = document.createElement('span');
                        const wordText = document.createTextNode(arrayOfEqualLengthWords_5[wordCounter]);
                        wordList.push(arrayOfEqualLengthWords_5[wordCounter]);

                        // increment the counters
                        wordCounter++;
                        wordCounterRow++;

                        // append the word to the textslot
                        word.appendChild(wordText)
                        word.classList.add('word');
                        textSlots[i].append(word);

                        // append it with a mark, preventing words to be side by side
                        const mark = document.createTextNode(marks[Math.floor(Math.random() * (marks.length - 1 - 0)) + 0]);
                        textSlots[i].append(mark);

                        // increment width counter
                        currentWidth += 5;
                    } else {
                        while (currentWidth <= rowMaxWidth) {
                            const mark = document.createTextNode(marks[Math.floor(Math.random() * (marks.length - 1 - 0)) + 0]);
                            textSlots[i].append(mark);
                            currentWidth++;
                        }
                    }
                }

                if (currentWidth >= rowMaxWidth) {
                    wordCounterRow = 0;
                    currentWidth = 0;
                    i++;
                }
            }

            // search for a password
            const wordSlots = $('.word');
            const password = wordList[Math.floor(Math.random() * (wordList.length - 1 - 0)) + 0];
            console.log(password);

            // hover handle
            const attemptSection = $('.attempt-section');
            let wordCopy = "";
            for (let i = 0; i < wordSlots.length; i++) {
                $(wordSlots[i]).hover(() => {
                    wordSlots[i].classList.add('hover');
                    wordCopy = '<span class="insert"> > ' + wordSlots[i].textContent + '</span>';
                    attemptSection.append(wordCopy);
                }, () => {
                    wordSlots[i].classList.remove('hover');
                    $('.insert').remove();
                })
            }

            // word likeness
            let likeness = (word, password) => {
                let j = 0;
                for (let i = 0; i < word.length; i++) {
                    if (word[i] == password[i]) {
                        j++;
                    }
                }

                return j;
            }

            // attempt handle
            let remainingAttempts = 3; // -1 because of the indexing
            let attempts = $('.attempt');
            const endgame = $('#endgame');
            for (let i = 0; i < wordSlots.length; i++) {
                $(wordSlots[i]).click(() => {
                    wordCopy = '<span> > ' + wordSlots[i].textContent + '</span>';
                    const wordAttempt = wordSlots[i].textContent;
                    attemptSection.append(wordCopy);

                    if (wordAttempt == password) {
                        attemptSection.append('<span>> Terminal cracked</span>')
                        endgame[0].classList.add('endgame');
                        window.setTimeout(() => {
                            endGame();
                        }, 2000);
                    } else {
                        attempts[remainingAttempts].classList.add('hide');
                        remainingAttempts--;

                        attemptSection.append('<span>> Entry denied</span>')
                        attemptSection.append('<span>> Likeness=' + likeness(wordAttempt, password) + '</span>');

                        if (remainingAttempts == -1) {
                            endGame();
                        }
                    }
                });
            }

            let endGame = () => {
                const endMsg = document.createElement('span');
                endMsg.append(document.createTextNode("> Terminal locked down"));
                attemptSection.append(endMsg);
                endgame[0].classList.add('endgame');
                resetGame();
            }
        }

        let resetGame = () => {
            $('body').html('');
            $('body').append('<span class="lead">> Restarting terminal</span>');
            window.setTimeout(() => {
                $('body').load('./mainWindow.html')
            }, 3000);
        }

        startGame();
    });
});