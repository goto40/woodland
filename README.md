# woodland
## Part 1: Python
see [woodland_book](woodland_book).
You need a running jupyter installation, like:
```
FROM jupyter/tensorflow-notebook

USER root

RUN apt update 
RUN apt install -y graphviz
RUN apt install -y tesseract-ocr tesseract-ocr-deu
RUN apt install -y fonts-humor-sans
RUN apt install -y git

USER $NB_UID

RUN rm -rf .cache/matplotlib/

RUN pip install pydot
RUN pip install pytesseract
RUN pip install ann_visualizer
RUN pip install graphviz
RUN pip install keras

USER $NB_UID
RUN pip install jupyter-book
RUN pip install pydotplus

USER root
RUN apt install zip
#RUN conda install --yes -c conda-forge xeus-cling && conda clean --all -f -y

USER $NB_UID
RUN pip install linear-tree

```
## Part 2: C++
See [cpp_tree_interpreter](cpp_tree_interpreter)
