// Red_Neuro.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Red_N.h"

int f(float x, float y, int equation)
{
	switch (equation)
	{
	case 0:
		return y > sin(x * 10) ? -1 : 1;
		break;
	case 1:
		return y > cos(x * 10) ? -1 : 1;
		break;
	case 2:
		return y > 2 * x ? -1 : 1;
		break;
	case 3:
		return y > tan(x * 10) ? -1 : 1;
		break;
	default:
		return y > cos(x * 10) ? -1 : 1;
		break;
	}
}

cv::Mat labelData(cv::Mat points, int equation)
{
	cv::Mat labels(points.rows, 1, CV_32FC1);
	for (int i = 0; i < points.rows; i++)
	{
		float x = points.at<float>(i, 0);
		float y = points.at<float>(i, 0);
		labels.at<float>(i, 0) = f(x, y, equation);
	}
	return labels;
}

int convertir(char distancia)
{
	if (distancia == ' ')
		return -1;
	int temp = distancia - '0';
	if (temp < 10)
		return temp;
	if (temp >= 49)
		return temp - 39;
	return temp + 19;
}

int main()
{
	/*
	cv::Ptr<cv::ml::ANN_MLP> a=cv::ml::ANN_MLP::create();
	int numTrainingpoints = 1000;//numero de puntos a entrenar.
	int numTestPoints = 100;//menor que la data para entrenar.
	int equation = 3;//numero de prueba
	cv::Mat trainingData(numTrainingpoints,2,CV_32FC1);
	cv::Mat testData(numTestPoints, 2, CV_32FC1);

	cv::randu(trainingData, 0, 1);
	cv::randu(testData, 0, 1);

	cv::Mat trainingClasses=labelData(trainingData,equation);
	cv::Mat testClasses=labelData(testData,equation);


	//Red Neuronal
	cv::Mat layers = cv::Mat(4, 1, CV_32SC1);
	layers.row(0) = cv::Scalar(2);
	layers.row(1) = cv::Scalar(10);
	layers.row(2) = cv::Scalar(15);
	layers.row(3) = cv::Scalar(1);

	cv::Ptr<cv::ml::ANN_MLP> b = cv::ml::ANN_MLP::create();
	b->setLayerSizes(layers);
	cv::Ptr<cv::ml::TrainData> tData=cv::ml::TrainData::create(trainingData, cv::ml::SampleTypes::ROW_SAMPLE, trainingClasses);
	b->train(tData);


	cv::Mat resultado;
	b->predict(testData, resultado);
	float r = resultado.at<float>(0, 0);
	*/

	Red_N prueba;
	prueba.cargar_data();
	prueba.entrenar();
	prueba.predecir();

	


    return 0;
}

