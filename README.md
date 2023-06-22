
# Text Spell Corrector

The Spell Corrector using Edit Distance and Dictionary is a program that aims to automatically correct misspelled words in a given paragraph. The program utilizes the concept of edit distance, which measures the number of operations required to transform one word into another, and a dictionary containing a list of correctly spelled words.

By employing the Wagner-Fischer algorithm, the program efficiently calculates the edit distance between the misspelled word and all words in the dictionary. It then selects the word with the lowest edit distance as the most probable correct word. In cases where multiple words have the same edit distance, the program chooses the most frequently used word in English. It has the same time complexity of O(n * m) but has a more efficient implementation. This algorithm guarantees an optimal solution by leveraging dynamic programming techniques, ensuring accurate and reliable suggestions for correcting misspelled words.

The program takes a paragraph as input and processes it word by word. It handles punctuation marks and capitalization, ensuring that corrected words are properly capitalized when necessary. The corrected paragraph is then displayed as output, indicating the corrected words.

The spell corrector project aims to provide an efficient and accurate solution for correcting spelling mistakes in various applications, such as text editors, search engines, and natural language processing systems.

The project is implemented in C++ and utilizes the chrono library for measuring execution time. It includes files for the dictionary and word frequencies, allowing for customization and expansion of the dictionary as needed.

With its modular design and customizable dictionary, the spell corrector can be enhanced in the future by incorporating machine learning techniques or integrating with larger language processing systems.


## Features

- Edit Distance Calculation: The program implements Wagner-Fischer algorithm to calculate the edit distance between misspelled words and dictionary words. This enables efficient and accurate identification of the most probable correct word.
- Dictionary-based Correction: The spell corrector utilizes a dictionary containing a list of correctly spelled words (about 194,000 words). It compares the edit distances of the misspelled word with words in the dictionary to identify the nearest correct word.
- Frequency-based Word Selection: In cases where multiple words have the same edit distance, the program selects the most frequently used word in English as the most probable correction. This improves the accuracy of the correction process.
- Handling of Punctuation and Capitalization: The program handles punctuation marks and capitalization within the input paragraph. It ensures that corrected words are properly capitalized when necessary and maintains the original structure of the paragraph.
- Customizable Dictionary: The spell corrector allows for the customization and expansion of the dictionary. This enables users to add new words or domain-specific terms to improve the correction accuracy for specific applications or industries.
- Execution Time Measurement: The program utilizes the chrono library to measure the execution time. This provides insights into the performance of the spell corrector and allows for optimization if needed.
- Modular Design: The project is implemented in C++ with a modular design, making it easy to understand, maintain, and enhance. The code is organized into functions and utilizes appropriate data structures for efficient word storage and retrieval.
- Potential for Future Enhancements: The spell corrector project can be further enhanced by incorporating machine learning techniques, such as language models or neural networks, to improve the correction accuracy. It also has the potential to be integrated into larger natural language processing systems for advanced language analysis and processing tasks.


## Usage 
- Compilation: Before running the spell corrector program, make sure you have a C++ compiler installed on your system. Use the appropriate compiler command to compile the source code file. For example, if you're using the GNU Compiler Collection (GCC), you can compile the code using the following command in the terminal:
- Dictionary and Frequency Files: Ensure that you have the dictionary and frequency files required for the spell corrector. By default, the program expects the dictionary to be in a file named "dict.txt" and the corresponding word frequencies in a file named "freq.txt". Make sure these files are present in the same directory as the compiled executable.

Note: You can customize the dictionary and frequency file names by modifying the file paths in the code if needed.
- Input Paragraph: After running the program, you will be prompted to enter a paragraph for spell correction. Type or paste the paragraph in the terminal and press Enter to proceed.
- Corrected Paragraph: The program will process the input paragraph and display the corrected version. The misspelled words will be replaced with the nearest correct words based on the edit distance and dictionary lookup. The corrected paragraph will be printed in the terminal.
- Execution Time: Upon completion, the program will display the execution time in milliseconds. This provides an indication of the spell correction performance.
- Follow these usage instructions to utilize the spell corrector effectively and ensure accurate correction of spelling mistakes in your paragraphs or texts.
![Screenshot 2023-06-21 183233](https://github.com/SwapnilGavali295/Text-Spell-Corrector/assets/137003175/41b844dc-a85a-4daa-a1db-68f4eef21242)
