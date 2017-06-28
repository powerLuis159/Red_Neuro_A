#include "stdafx.h"
#include "Red_N.h"


Red_N::Red_N()
{
	cv::Mat layers = cv::Mat(4, 1, CV_32SC1);
	layers.row(0) = cv::Scalar(160'000);
	layers.row(1) = cv::Scalar(400);
	layers.row(2) = cv::Scalar(20);
	layers.row(3) = cv::Scalar(1);

	red = cv::ml::ANN_MLP::create();
	red->setLayerSizes(layers);
}

Red_N::Red_N(cv::Mat layers)
{
	red = cv::ml::ANN_MLP::create();
	red->setLayerSizes(layers);
}

void Red_N::cargar_data()
{
	cv::Mat temp;
	cv::Mat testData(50, 400 * 400, CV_32F);

	std::string path="C:/Users/LRona/Downloads/Imagenes geometricas Ale/CUADRADOS-IMAGEN/CUADRADOS IMAGEN/Cuadrado";
	

	for (size_t k = 0; k < 30; k++)
	{
		temp = cv::imread((path + std::to_string(k+1) + ".jpg"),cv::ImreadModes::IMREAD_GRAYSCALE);
		cv::resize(temp, temp, cv::Size(400, 400));
		for (size_t i = 0; i < temp.rows; i++)
		{
			for (size_t j = 0; j < temp.cols; j++)
			{
				testData.at<float>(k, i*400+j) = (float)temp.at<unsigned char>(i, j)/256;
			}

		}
	}

	path = "C:/Users/LRona/Downloads/Imagenes geometricas Ale/triangulos/t";
	cv::resize(temp, temp, cv::Size(400, 400));

	for (size_t k = 0; k < 20; k++)
	{
		temp = cv::imread((path + std::to_string(k + 1) + ".jpg"), cv::ImreadModes::IMREAD_GRAYSCALE);
		cv::resize(temp, temp, cv::Size(400, 400));
		for (size_t i = 0; i < temp.rows; i++)
		{
			for (size_t j = 0; j < temp.cols; j++)
			{
				testData.at<float>(k+30, i*400+j) = (float)temp.at<unsigned char>(i, j) / 256;
			}

		}
	}

	cv::Mat testClass(50, 1, CV_32F);
	for (size_t i = 0; i < 30; i++)
	{
		testClass.at<float>(i, 0) = 1.0;
	}
	for (size_t i = 30; i < 50; i++)
	{
		testClass.at<float>(i, 0) = -1.0;
	}


	tData = cv::ml::TrainData::create(testData, cv::ml::SampleTypes::ROW_SAMPLE, testClass);
	//red->train(testData, cv::ml::SampleTypes::ROW_SAMPLE, testClass);
	
}

void Red_N::entrenar()
{
	red->train(tData);
}

void Red_N::predecir()
{
	cv::Mat temp;
	cv::Mat testData(60, 400 * 400, CV_32F);

	std::string path = "C:/Users/LRona/Downloads/Imagenes geometricas Ale/images/";


	for (size_t k = 0; k < 60; k++)
	{
		temp = cv::imread((path + std::to_string(k + 1) + ".png"), cv::ImreadModes::IMREAD_GRAYSCALE);
		cv::resize(temp, temp, cv::Size(400, 400));
		for (size_t i = 0; i < temp.rows; i++)
		{
			for (size_t j = 0; j < temp.cols; j++)
			{
				testData.at<float>(k, i * 400 + j) = (float)temp.at<unsigned char>(i, j) / 256;
			}

		}
	}
	cv::Mat resultado;
	red->predict(testData, resultado);
	int contador=0;
	for (size_t i = 0; i < 60; i++)
	{
		if (resultado.at<float>(i, 0) > 0)
			contador++;
	}
	std::cout << "resultado: cuadrados: " << contador << ". triangulos: " << 60 - contador;
}


Red_N::~Red_N()
{
}
