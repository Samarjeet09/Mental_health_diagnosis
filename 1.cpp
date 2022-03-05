// Mental Health
#include <iostream>
using namespace std;

int decider = 1;
int rating(int, int);
void drugsf();
void alcoholf();
void dementiaf();
void delirium();
void acute_psychotic_disorderf();
void chronic_psychotic_disorderf();
void Adjusment_disorderf();
void end_karwado();
void phobic_disorder();
void panic_disorder();
void Generalized_anxiety();
void Mixed_anxiety_and_Depression();
void depressionf();
void Bipolar_disorder();
void Dissociative_disorder();
void sleep_disorder();
void eating_disorder();
void Neurastheniaf();
void Hyperkineticf();
void Conduct_disorder();
int kessler_pysco_test();

int main()
{
    int alcohol, drugs, strange, agitation, memoryloss, confusion, stress_reaction, Psyco_distress;
    int phobic, panic, depression_count, bipolar, neurasrthenia, dsissociative;
    // Separate Page
    cout << "Do you consume alcohol frequently ? (1/0)" << endl;
    cin >> alcohol;
    if (alcohol == 1)
    {
        alcoholf();
        end_karwado();
    }
    cout << "Do u consume drugs? (1/0)" << endl;
    cin >> drugs;
    if (drugs == 1)
    {
        drugsf();
        end_karwado();
    }

    cout << "Do you feel agitated very frequently (1/0)" << endl;
    cin >> agitation;
    cout << "Do you feel you are very frequently forgetting things (1/0)" << endl;
    cin >> memoryloss;
    cout << "Do you feel you are confused very frequently (1/0)" << endl;
    cin >> confusion;

    if ( agitation == 1 || memoryloss == 1 || confusion == 1)
    {
        cout << "Do you have a history of chronic memory loss?(1/0)";
        cin >> strange;

        if (strange == 1)
        {
            dementiaf();
            end_karwado();
        }

        cout << "Was this(memory loss) all due to a medical problem?(1/0)";
        cin >> strange;

        if (strange == 1)
        {
            delirium();
            end_karwado();
        }

        cout << "Are these conditons arising recently?(1/0)";
        cin >> strange;

        if (strange == 1)
        {
            acute_psychotic_disorderf();
            end_karwado();
        }

        else
        {
            chronic_psychotic_disorderf();
            end_karwado();
        }
    }

    cout << "Do you fail to remain calm in stressful situations (1/0)" << endl;
    cin >> stress_reaction;
    if (stress_reaction == 1)
    {
        Adjusment_disorderf();
        end_karwado();
    }
    Psyco_distress = kessler_pysco_test();
    if (Psyco_distress == 1)
    {
        cout << "Are you afraid of specfic places? (1/0)" << endl;
        cin >> phobic;
        if (phobic == 1)
        {
            phobic_disorder();
            end_karwado();
        }
        cout << "Have you ever experienced an abrupt surge of intense fear or discomfort seemingly out of the blue, that lasted several minutes? (1/0)" << endl;
        cin >> panic;
        cout << "Out of 7 days of week on an average what is the number of days you feel sad or slow(0/7)" << endl;
        cin >> depression_count;
        if (panic == 1)
        {
            panic_disorder();
            end_karwado();
        }
        else if (panic == 1 && (depression_count > 0 && depression_count < 4))
        {
            Mixed_anxiety_and_Depression();
            end_karwado();
        }
        else
        {
            Generalized_anxiety();
            end_karwado();
        }
        cout << "Do you have history of maniac episodes ? (1/0)" << endl;
        cin >> bipolar;
        if (depression_count >= 2 && bipolar == 0)
        {
            depressionf();
            end_karwado();
        }
        else if (bipolar == 0 && depression_count == 0)
        {
            cout << "Do you feel fatigued on daily basis ? (1/0) " << endl;
            cin >> neurasrthenia;
            if (neurasrthenia == 1)
            {
                Neurastheniaf();
                end_karwado();
            }
        }
        else
        {
            Bipolar_disorder();
            end_karwado();
        }
    }
    cout << "Do you feel you become dramatic without the influence of your cconscious mind ? (1/0)" << endl;
    cin >> dsissociative;
    if (dsissociative == 1)
    {
        Dissociative_disorder();
        end_karwado();
    }
    else
    {
        cout << "Do you feel fatigued on daily basis ? (1/0)" << endl;
        cin >> neurasrthenia;
        if (neurasrthenia == 1)
        {
            Neurastheniaf();
            end_karwado();
        }
    }
    Hyperkineticf();
    Conduct_disorder();
    eating_disorder();
    sleep_disorder();

    return 0;
}

int rating(int input, int questions)
{
    if (input >= (questions * 5)) // dekho har Q 10 marks ka hai and then we assume
        return 1;                 // ki if score is greater than half (/2) you are positive
    else if (input < (questions * 10) / 4)
        return -1;
    else
        return 0;
}

void end_karwado()
{   cout<<"Do you wish to continue the test ? (press 0 to exit)"<<endl;
    cin>>decider;
    if (decider == 0)
    {
        cout << "THANK YOU FOR TAKING THE TEST" << endl;
        cout << "ALTHOUGH THIS TEST IS REFFERENCED BY \"ICD-10 Chapter V Primary Care Version\"" << endl;
        cout << "This is an indicatory test and offcial consulation to a psychatrist is recommended for proper diagnosis " << endl;
        exit(0);
    }
}

void drugsf()
{   cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "How often do you feel depressed on a scale of 0-10?" << endl;
    cin >> a;
    sum += a;
    cout << "How often do you feel nervous on a scale of 0-10?" << endl;
    cin >> a;
    sum += a;
    cout << "How much difficulty do you face while sleeping on a scale of 0-10" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you exihibit the following symptoms(0/10) : nausea\nsweating\ntremors\nanxiety\ntremors\nhallucinations" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently you observe unexplained change in your behaviour, appearance, or functioning? (0/10)" << endl;
    sum += a;
    b = rating(sum, 5);

    if (b == 1)
        cout << "You might be suffering from drug use disorder (F11#)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of drug use disorder" << endl;
}

void alcoholf()
{   
    cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "How often do you feel depressed on a scale of 0-10?" << endl;
    cin >> a;
    sum += a;
    cout << "How often do you feel nervous on a scale of 0-10?" << endl;
    cin >> a;
    sum += a;
    cout << "How much difficulty do you face while sleeping on a scale of 0-10" << endl;
    cin >> a;
    sum += a;
    cout << "How often do you forget about somthing (0-10)" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently would you say you experience sweating, tremors, morning sickness, hallucinations on a scale of 0-10?" << endl;
    cin >> a;
    sum += a;
    b = rating(sum, 5);

    if (b == 1)
        cout << "You might be suffering from alcohol use disorder (F10)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of alchol use disorder" << endl;
}

void dementiaf()
{   
    cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "Do you have problem while recalling recent events " << endl;
    cin >> a;
    sum += a;
    cout << "How quickly do you tend to lose interst ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you tend to lose control over your emotions ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you tend to face problem in everyday fuctioning ?" << endl;
    cin >> a;
    sum += a;
    b = rating(sum, 4);

    if (b == 1)
        cout << "You might be suffering from Dementia (F00*)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of Dementia" << endl;
}

void delirium()
{   
    cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "How often u find youself in confusion" << endl;
    cin >> a;
    sum += a;
    cout << "How often do feel you are hearing voices" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you see visuals which distract you or hear voices" << endl;
    cin >> a;
    sum += a;
    cout << "Rate the diffulty in orienting yourself?" << endl;
    cin >> a;
    sum += a;
    cout << "Rate the diffulty you have in sleeping (reversal of sleeping pattern)?" << endl;
    cin >> a;
    sum += a;
    cout << "Rate your have diffulty in speaking?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do u feel the urge to cut yourself off from others?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently Do you feel suspicious of others?" << endl;
    cin >> a;
    sum += a;
    b = rating(sum, 8);

    if (b == 1)
        cout << "You might be suffering from DELIRIUM (F05)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of DELIRIUM" << endl;
}

void acute_psychotic_disorderf()
{   cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "How often u find youself Hearing voices in your head?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do u find yourself believing in strange beliefs " << endl;
    cin >> a;
    sum += a;
    cout << "How often do u feel confused" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do u feel apprehensive?" << endl;
    cin >> a;
    sum += a;
    cout << "Rate the diffulty you face in speaking?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently Do you feel suspicious of others?" << endl;
    cin >> a;
    sum += a;
    b = rating(sum, 6);

    if (b == 1)
        cout << "You might be suffering from Acute Psychotic Disorder (F23*)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of Acute Psychotic Disorder " << endl;
}

void chronic_psychotic_disorderf()
{
    cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "How often u find youself Hearing voices in your head?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do u find yoursself believing in strange beliefs " << endl;
    cin >> a;
    sum += a;
    cout << "How often do u feel you face problems while thinking?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you get distracted?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you imagine having and animal or and unusal object inside your body?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently you think you have a supernatural power?" << endl;
    cin >> a;
    sum += a;
    b = rating(sum, 6);

    if (b == 1)
        cout << "You might be suffering from Chronic Psychotic Disorder (F23*)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of Chronic Psychotic Disorder " << endl;
}

void Adjusment_disorderf()
{
    cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "Rate the diffucluty you facein sleeping?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do u face a stressful event in your workplace?" << endl;
    cin >> a;
    sum += a;
    cout << "How often do u feel you sad or low?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel unable to cope?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel anxious ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel palpitations ?" << endl;
    cin >> a;
    sum += a;
    b = rating(sum, 6);

    if (b == 1)
        cout << "You might be suffering from Adjusment Disorder (F43*)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of Adjusment Disorder " << endl;
}

void phobic_disorder()
{
    cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "How often do you feel Shortness of breath?" << endl;
    cin >> a;
    sum += a;
    cout << "How unlikely are you to travel to crowded places ?" << endl;
    cin >> a;
    sum += a;
    cout << "How often do u feel scared of going out?" << endl;
    cin >> a;
    sum += a;
    cout << "How uncomfortable are u with speaking in public?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel anxious in social events ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel palpitations ?" << endl;
    cin >> a;
    sum += a;
    b = rating(sum, 6);

    if (b == 1)
        cout << "You might be suffering from Phobic Disorder (F40)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of Phobic Disorder " << endl;
}

void panic_disorder()
{   
    cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "How frequently do u Find diffculty in breathing?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do u feel chest pain?" << endl;
    cin >> a;
    sum += a;
    cout << "How often do u feel you sad or low?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you face anxiety attacks?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel a fear of a personal disaster ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel palptations?" << endl;
    cin >> a;
    sum += a;
    b = rating(sum, 6);

    if (b == 1)
        cout << "You might be suffering from Panic Disorder (F41.0)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of Panic Disorder " << endl;
}

void Generalized_anxiety()
{
    cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "Rate your diffculty in sleeping ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do u face a stressfull event in your workplace?" << endl;
    cin >> a;
    sum += a;
    cout << "How often do u feel tensed " << endl;
    cin >> a;
    sum += a;
    cout << "What would be the frequency of headaches in a day ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel losing concentration ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel restless?" << endl;
    cin >> a;
    sum += a;
    b = rating(sum, 6);

    if (b == 1)
        cout << "You might be suffering from Generalized Anxiety (F41.1)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of Generalized Anxiety " << endl;
}

void Mixed_anxiety_and_Depression()
{
    cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "Rate your diffculty in sleeping?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel out of energy?" << endl;
    cin >> a;
    sum += a;
    cout << "How often do you feel losing concentration " << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you experience dizzyness ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do thoughts of sucide strike you ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel palpitations?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel tremors?" << endl;
    cin >> a;
    sum += a;
    cout << "do you think your apptite is distubed?" << endl;
    cin >> a;
    sum += a;
    cout << " How often do you feel you are losing interst in your daily activites?" << endl;
    cin >> a;
    sum += a;
    cout << "How often do you experience loss of your libdo?" << endl;
    cin >> a;
    sum += a;
    b = rating(sum, 10);

    if (b == 1)
        cout << "You might be suffering from Mixed Anxiety and Depression (F41.2)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of Mixed Anxiety and Depression " << endl;
}

void depressionf()
{
    cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "Rate your difficulty in sleeping?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you accuse yourself ?" << endl;
    cin >> a;
    sum += a;
    cout << "How often do you feel Fatigue " << endl;
    cin >> a;
    sum += a;
    cout << "What would be the frequency of headaches in a day ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel losing concentration ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel restless?" << endl;
    cin >> a;
    sum += a;
    cout << "Do you feel you are losing interst in your daily activites?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do thoughts of sucide strike you ?" << endl;
    cin >> a;
    sum += a;
    cout << "How often do you experience loss of your libdo?" << endl;
    cin >> a;
    sum += a;
    cout << "Do you think your apptite is distubed?" << endl;
    cin >> a;
    sum += a;
    b = rating(sum, 10);

    if (b == 1)
        cout << "You might be suffering from Depression(F32#)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of Depression" << endl;
}

void Bipolar_disorder()
{   cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "Do you feel decreased need for sleeping?" << endl;
    cin >> a;
    sum += a;
    cout << "Give yourself and importance a number (1-10) ?" << endl;
    cin >> a;
    sum += a;
    cout << "How often do u periods of increased enegry  followed by sadness " << endl;
    cin >> a;
    sum += a;
    cout << "Do you feel you hallucinate ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel losing concentration ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel restless?" << endl;
    cin >> a;
    sum += a;
    cout << "do you feel you are losing interst in your daily activites?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do thoughts of sucide strike you ?" << endl;
    cin >> a;
    sum += a;
    cout << "do u think your apptite is distubed?" << endl;
    cin >> a;
    sum += a;
    cout << "How often do u feel Fatigue?" << endl;
    cin >> a;
    sum += a;
    b = rating(sum, 10);

    if (b == 1)
        cout << "You might be suffering from Bipolar Disorder(F31)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of Bipolar Disorder" << endl;
}

void Dissociative_disorder()
{
    cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "How frequently do u Find diffculty in breathing?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do u feel you switch personalites form time to time?" << endl;
    cin >> a;
    sum += a;
    cout << "How often do u feel dramatic?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you face anxiety attacks?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel a fear of losing your identity ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you seek attention from others?" << endl;
    cin >> a;
    sum += a;
    b = rating(sum, 6);

    if (b == 1)
        cout << "You might be suffering from Dissociative Disorder (F44)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of Dissociative Disorder " << endl;
}

void sleep_disorder()
{
    cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "How frequently do u Find diffculty sleeping?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do u feel your sleep was unrefreshing?" << endl;
    cin >> a;
    sum += a;
    cout << "How often do u feel you sad or low?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel restless?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you experience periods of awakeness ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you consume caffine in a week (0-10?" << endl;
    cin >> a;
    sum += a;
    b = rating(sum, 6);

    if (b == 1)
        cout << "You might be suffering from Sleep Disorder (F51)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of Sleep Disorder " << endl;
}

void Neurastheniaf()
{
    cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "How frequently do u Find yourself out of energy?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do u encounter pains and aches?" << endl;
    cin >> a;
    sum += a;
    cout << "How often are unable to complete tasks?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel irritated?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel you are unable to relax ?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you lose concentration" << endl;
    cin >> a;
    sum += a;
    cout << "How often do you experience loss of your libdo?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you feel dizzy ?" << endl;
    cin >> a;
    sum += a;
    b = rating(sum, 8);

    if (b == 1)
        cout << "You might be suffering from Neurasthenia (F48.0)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of Neurasthenia " << endl;
}

void eating_disorder()
{
    cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "Rate your fear of being fat or gaining weight?" << endl;
    cin >> a;
    sum += a;
    cout << "Rate your efforts of your weight management?" << endl;
    cin >> a;
    sum += a;

    b = rating(sum, 2);

    if (b == 1)
        cout << "You might be suffering from Eating Disorders (F50)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of Eating Disorders " << endl;
}

void Hyperkineticf()
{
    cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "Are you impulsive?" << endl;
    cin >> a;
    sum += a;
    cout << "Do you have poor concentration?" << endl;
    cin >> a;
    sum += a;
    cout << "Do you feel you lack of ability to listen to others?" << endl;
    cin >> a;
    sum += a;
    cout << "Do you have poor concentrationfeel restless?" << endl;
    cin >> a;
    sum += a;

    b = rating(sum, 4);

    if (b == 1)
        cout << "You might be suffering from Hyperkinetic disorder (F90)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of Hyperkinetic disorder " << endl;
}

void Conduct_disorder()
{
    cout<<"The scale -> 0 being the least and 10 being the maximum"<<endl;
    int a, b, sum = 0;
    cout << "Do you enjoy vandalism?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you indulge in stealing?" << endl;
    cin >> a;
    sum += a;
    cout << "How frequently do you Lie?" << endl;
    cin >> a;
    sum += a;
    cout << "Do you have poor concentrationfeel restless?" << endl;
    cin >> a;
    sum += a;

    b = rating(sum, 4);

    if (b == 1)
        cout << "You might be suffering from Conduct disorder (F91#)" << endl;
    else if (b == -1)
        cout << "There are very few to no symptoms of Conduct disorder " << endl;
}

int kessler_pysco_test()
{
    int a, b, sum = 0;
    cout << "On a Scale of 1-5" << endl;
    cout << "In the past 4 weeks, about how often did   you feel tired out for no good reason?" << endl;
    cin >> a;
    sum += a;
    cout << "In the past 4 weeks, about how often did you feel nervous? " << endl;
    cin >> a;
    sum += a;
    cout << "In the past 4 weeks, about how often did you feel so nervous that nothing could calm you down?" << endl;
    cin >> a;
    sum += a;
    cout << "In the past 4 weeks, about how often did you feel hopeless? " << endl;
    cin >> a;
    sum += a;
    cout << "In the past 4 weeks, about how often did you feel restless or fidgety? " << endl;
    cin >> a;
    sum += a;
    cout << "In the past 4 weeks, about how often did you feel so restless you could not sit still? " << endl;
    cin >> a;
    sum += a;
    cout << "In the past 4 weeks, about how often did you feel depressed? " << endl;
    cin >> a;
    sum += a;
    cout << "In the past 4 weeks, about how often did you feel that everything was an effort? " << endl;
    cin >> a;
    sum += a;
    cout << "In the past 4 weeks, about how often did you feel so sad that nothing could cheer you up? " << endl;
    cin >> a;
    sum += a;
    cout << "In the past 4 weeks, about how often did you feel worthless? " << endl;
    cin >> a;
    sum += a;

    if (sum >= 25)
        return 1;
    else
        return 0;
}