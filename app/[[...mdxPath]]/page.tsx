import { Metadata } from "next";
import { generateStaticParamsFor, importPage } from "nextra/pages";
import { useMDXComponents } from "../../mdx-components";
import PostFooter from "../components/PostFooter";

export const generateStaticParams = generateStaticParamsFor("mdxPath");

export async function generateMetadata(props): Promise<Metadata> {
  const params = await props.params;
  const { metadata } = await importPage(params.mdxPath);
  return metadata;
}

const Wrapper = useMDXComponents().wrapper;

export default async function Page(props) {
  const params = await props.params;
  const result = await importPage(params.mdxPath);
  const { default: MDXContent, toc, metadata } = result;

  return (
    <Wrapper toc={toc} metadata={metadata} sourceCode={null}>
      <MDXContent {...props} params={params} />
      <PostFooter {...metadata} />
    </Wrapper>
  );
}
