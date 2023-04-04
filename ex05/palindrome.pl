$input = <STDIN>;

chomp($input);

if ($input eq reverse $input)
{
    print("palindrome.\n");
}
else
{
    print("not palindrome.\n");
}
