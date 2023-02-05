# KNN
The k-nearest neighbors algorithm, also known as KNN or k-NN, is a non-parametric, supervised
learning classifier, which uses proximity to make classifications or predictions about the grouping of an
individual data point. For classification problems, a class label is assigned on the basis of a majority
vote—i.e. the label that is most frequently represented around a given data point is used. While this is
technically considered “plurality voting”, the term, “majority vote” is more commonly used in literature.
The training examples are vectors in a multidimensional feature space, each with a class label. The
training phase of the algorithm consists only of storing the feature vectors and class labels of the training
samples.

In the classification phase, k is a user-defined constant, and an unlabeled vector (a query or test point)
is classified by assigning the label which is most frequent among the k training samples nearest to that
query point.A commonly used distance metric for continuous variables is Euclidean distance.




![image](https://user-images.githubusercontent.com/69524864/216815898-9de1864b-23b9-42f6-9176-f3cdcb3dc880.png)








In this project, primarily training data and test data were created. The size of the training data is 30 and
the size of the test data is 10. Each training data has 2 features and 3 categories. These features are
randomly selected between -5 and +5. The category value of traning data with ID value between 0 and
9 is assigned as 0. The category value of traning data between 10 and 19 is assigned as 1. The category
value of traning data between 20 and 29 is assigned as 2. It is not clear. Which category was predicted
as a result of the KNN algorithm. The ID values of the test data are between 30 and 39. Their features
are between -5 and +5 and were determined randomly. After these features are determined, the
categories of the test data are estimated by determining the Euclidean distance and plurality vote of
neighbor's criterion.


First, I created a DataSet class in which the ID, category ID, Feature X, Feature Y which are properties
of the training data used as vector. I stored each of the features I created in vector.
Then I created the KNN class, where I calculate the distance, nearest neighborhood and estimated
category IDs between the test data and training data.
I created the Graph class, which visually outputs the training data and predicted category values. I also
used the graphics library to visualize the data.
In the driver code, I determined the properties of the training data. I created an object for each class
and called them in order.
